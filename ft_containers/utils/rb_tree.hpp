#pragma once

#include <iostream>
#include <memory>
#include "rb_tree_iterator.hpp"
#include "rb_tree_funct.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"

namespace ft
{
	template <typename T>
	struct Node
	{
		//Member types
		typedef	T											value_type;
		typedef size_t  									size_type;
 		typedef value_type*									pointer;
		typedef	value_type	const * 						const_pointer;
		typedef value_type&									reference;
		typedef	value_type	const & 						const_reference;

		Node		*left;      //Left child of the node
		Node		*right;     //Right child of the node
		Node		*parent;    //Parent of the node
		bool		is_black;   //Colour of the node (true=BLACK or false=RED)
		value_type	value;      //Value of the node

		//Functions
		Node(T val): left(nullptr), right(nullptr), parent(nullptr), is_black(false), value(val) {}
		Node(Node const& copy): left(nullptr), right(nullptr), parent(nullptr), is_black(copy.is_black), value(copy.value) {}

		Node *gramp() { return(parent ? (parent->parent ? parent->parent : nullptr) : nullptr); }		//Returns a Node pointer of this node's grandparent
		Node *uncle() 																					//Returns a Node pointer of this node's uncle
		{
			if(gramp() != nullptr)
				if(parent->isThisLeftC())
					return(gramp()->right);
			if(gramp() != nullptr)
				if(parent->isThisRightC())
					return(gramp()->left);
			return nullptr;
		}
		Node *sibiling()																				//Returns a Node pointer of this node's sibiling
		{
			if(isRight() && parent->left)
				return (parent->left);
			else if (isLeft() && parent->right)
				return (parent->right);
		}
	};

	template <typename T, class Allocator = std::allocator<Node<T> >, class Compare = std::less<T> >
	class RBTree
	{
		public:
			typedef T											value_type;
			typedef Node<T>* 									node_pointer;
			typedef Allocator									allocator_type;
			typedef Compare										value_compare;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::rb_tree_iterator<T>						iterator;
			typedef ft::const_rb_tree_iterator<T>				const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::const_reverse_iterator<const_iterator>	const_reverse_iterator;
			
			RBTree(const value_compare& comp = value_compare(), const allocator_type& alloc = allocator_type()) : 
				_root(nullptr), _begin(nullptr), _end(_begin), _alloc(alloc), _size(0), _comp(comp) 
			{
				_end->is_black = false;
				_end->left = nullptr;
				_end->parent = nullptr;
				_end->right = nullptr;
				_end->value = NULL;
			}
			RBTree() : _size(0)
			{
				_root = nullptr;
				_begin = nullptr;
				_end = _alloc.allocate(1);
				_end = nullptr;					
			}
			explicit RBTree(const value_compare& comp) : _size(0), _comp(comp)
			{
				_root = nullptr;
				_begin = nullptr;
				_end = _alloc.allocate(1);
				_end = nullptr;
			}
			explicit RBTree(const allocator_type& a) : _alloc(a), _size(0)
			{
				_root = nullptr;
				_begin = nullptr;
				_end = _alloc.allocate(1);
				_end = nullptr;					
			}
			RBTree(const RBTre& t)
			{
				if(this != &t)
				{
					_comp = t._comp;
					if(_alloc != t._alloc)
						clear();
					else
						_alloc = t._alloc;
					_end = _alloc.allocate(1);
					for(iter i = t.begin(); i != t.end(); i++)
						insert(*i);
				}
			}
			~RBTree() {}
			RBTree(Node &copy) { *this = copy; }

			RBTree& operator=(const RBTree& x)
			{
				if(_size != 0)
					clear();
				_comp = x.value_comp();
				_alloc = x._alloc;
				insert(x.begin(), x.end());
				return *this;
			}

			//Getters
			node_pointer 	getRoot()			{ return _root;	}
			node_pointer 	getBegin()			{ return _begin;}
			node_pointer 	getEnd()			{ return _end;	}
			allocator_type&	getAlloc()			{ return _alloc;}
			value_compare& value_comp()			{ return _comp; }
			const value_compare& value_comp()	{ return _comp; }

			//Capacity
			size_type size() const { return _size; }
            size_type max_size() const { return (_alloc.max_size()); }

			//Setters
			void	setRoot(node_pointer x) { _root = x; }
			void 	setBegin()
			{
				node_pointer tmp = _root;
				while(tmp->left)
					tmp = tmp->left;
				_begin = tmp;
			}
			void 	setEnd()
			{
				node_pointer tmp = _root;
				while(tmp->right)
					tmp = tmp->right;
				_end = tmp->right;
				_end->is_black = true;
				_end->parent = tmp;
				_end->value = NULL;
				_end->right = nullptr;
				_end->left = nullptr;
			}

			void	find_new_root(node_pointer ptr)
			{
				while(ptr->parent)
					ptr = ptr->parent;
				_root = ptr;
			}

			void	find_new_end(node_pointer ptr)
			{
				while(ptr->right)
					ptr = ptr->right;
				ptr->right = _end;
				_end->parent = ptr;
				_end->left = nullptr;
				_end->right = nullptr;
			}

			//Iterators
			iterator 			begin() const{ return iterator(_begin); }
			iterator 			end() const{ return iterator(_end); }
			reverse_iterator 	rbegin() const{ return reverse_iterator(_end); }
			reverse_iterator 	rend() const{ return reverse_iterator(_begin); }
			
			//Modifiers
			template <class U> Node<U>* newnode(const U& value)
			{
				Node<U> *a = _alloc.allocate(1);
				Node<U> n(value);
				_alloc.construct(a, n);
				return (a);
			}
			
			void clear()
			{
				erase_rng(begin(), end());
				_size = 0;
				_begin = _end;
			}
			void erase( iterator pos )
			{
				pointer np = pos.base();
				iterator r = remove_node_pointer(np);
				_alloc.deallocate(pos.base(), 1);
				if(_size > 0)
					find_new_end(_root);	
			}
			void erase_rng( iterator first, iterator last )
			{
				iterator tmp = first;
				for( ; tmp <= last ; tmp++)
					erase(first);
			}

			template <class _Key>
			size_type erase_key(const _Key& __k)
			{
				iterator r = find(__k);
				if (r == end())
					return (0);
				erase_position(r);
				return 1;
			}

			void swap(__tree& __t)
			{
				std::swap(_begin_node, __t._begin_node);
				std::swap(_end_node, __t._end_node);
				std::swap(_alloc, __t._alloc);
				std::swap(_size, __t._size);
				std::swap(_value_compare, __t._value_compare);
			}

			ft::pair<iterator, bool> insert( const value_type& value )
			{
				node_pointer new_node = nullptr;						
				node_pointer ptrToCompare = nullptr;					//it will act as the root (if it exists) and then a node
				node_pointer takeRoot = getRoot();
				bool isInserted = false;
				if (takeRoot != nullptr && _size != 0) 					//if root exists
				{
					ptrToCompare = takeRoot;
					while(true)
					{
						if(value_comp()(value, ptrToCompare->value))	//if value is lesser than the root (or the node)
						{
							if(ptrToCompare->left != nullptr)			//if there is a left child
								ptrToCompare = ptrToCompare->left;		//ptrToCompare will move to its left-child
							else
							{
								new_node = newnode(value);
								new_node->parent = ptrToCompare;
								ptrToCompare->left = new_node;
								isInserted = true;
								break;
							}
						}
						else if(value_comp()(ptrToCompare->value, value))	//if value is greater thant the root (or the node)
						{
							if(ptrToCompare->right != nullptr)			//if there is a right child
								ptrToCompare = ptrToCompare->right;		//ptrToCompare will move to its right-child
							else
							{
								new_node = newnode(value);
								new_node->parent = ptrToCompare;
								ptrToCompare->right = new_node;
								isInserted = true;
								break;
							}
						}
						else											//if the node with the same value already exists
						{
							if(ptrToCompare->left == nullptr && (ptrToCompare->right != nullptr || ptrToCompare->right == nullptr))
							{
								new_node = newnode(value);
								new_node->parent = ptrToCompare;
								ptrToCompare->left = new_node;
								isInserted = true;
								break;
							}
							else if(ptrToCompare->left != nullptr && ptrToCompare == nullptr)
							{
								new_node = newnode(value);
								new_node->parent = ptrToCompare;
								ptrToCompare->right = new_node;
								isInserted = true;
								break;
							}
							else if(ptrToCompare->left != nullptr && ptrToCompare->right != nullptr)
								ptrToCompare = ptrToCompare->right;
						}
					}
				}
				else
				{
					_root = newnode(value);
					node_pointer r = _root;
					_size++;
					_root->right = _end;
					_root->isBlack = BLACK;
					_end->right = nullptr;
					_end->left = nullptr;
					_end->parent = _root;
					_begin = _root;
					return ft::pair<iterator,bool>((iterator)r, true);
				}
				if(_begin->left != nullptr)
					_begin = _begin->left;
				if(inserted == true)
				{
					balance_after_insert(takeRoot(), new_node);
					find_new_root(new_node);
					_size++;
				}
				node_pointer r = new_node;
				return ft::pair<iterator,bool>((iterator)r, true);
			}

			iterator insert( iterator hint, const value_type& value )
			{
				ft::pair<iterator, bool> pos;
				(void) hint;
				pos = insert(value);
				return(pos.first);
			}

			iterator __remove_node_ptr(node_pointer ptr)
			{
				iterator _r(ptr);
				++_r;
				if(_begin == ptr)
					_begin = _r.base();
				--_size;
				removePtrTree(root, static_cast<node_pointer>(ptr));
				find_new_root();
				return _r;
			}

			//Map operators
			template <class key_type>
			iterator find( const key_type& key )
			{

			}

			template <class key_type>
			const_iterator find( const key_type& key ) const
			{

			}

			template <class key_type>
			size_type count( const key_type& key ) const
			{

			}

			template <class key_type>
			ft::pair<iterator,iterator> equal_range(const key_type& key)
			{

			}

			template <class key_type>
			ft::pair<const_iterator,const_iterator> equal_range(const key_type& key) const
			{

			}
			
			template <class key_type>
			iterator lower_bound( const key_type& key )
			{

			}

			template <class key_type>
			const_iterator lower_bound( const key_type& key ) const
			{
				
			}

			template <class key_type>
			iterator upper_bound( const key_type& key )
			{

			}

			template <class key_type>
			const_iterator upper_bound( const key_type& key ) const
			{
				
			}
		protected:
			node_pointer		_root;
			node_pointer		_begin;
			node_pointer 		_end;
			allocator_type		_alloc;
			value_compare		_comp;
			size_type			_size;
	};
}
