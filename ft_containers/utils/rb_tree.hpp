#pragma once

#include <iostream>
#include <memory>
#include "rb_tree_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"
#include <map>

namespace ft
{
	enum
	{
		BLACK,
		RED
	};

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
		bool		color;      //Colour of the node (BLACK or RED)
		value_type	value;      //Value of the node

		//Functions
		Node(const_reference val=value_type()): left(nullptr), right(nullptr), parent(nullptr), color(RED), value(val) {}
		Node(Node const& copy): left(nullptr), right(nullptr), parent(nullptr), color(copy.color), value(copy.value) {}

		bool isThisRightC() { return(parent && this == parent->right); }								//Checks if this node is a right child
		bool isThisLeftC() { return(parent && this == parent->left); }									//Checks if this node is a left child
		bool isBlack() { return !(this->color); }														//Checks if the current node is black
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
				_end->color = RED;
				_end->left = nullptr;
				_end->parent = nullptr;
				_end->right = nullptr;
				_end->value = NULL;
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

			void setBegin()
			{
				node_pointer tmp = _root;
				while(tmp->left)
					tmp = tmp->left;
				_begin = tmp;
			}
			void setEnd()
			{
				node_pointer tmp = _root;
				while(tmp->right)
					tmp = tmp->right;
				_end = tmp->right;
				_end->color = BLACK;
				_end->parent = tmp;
				_end->value = NULL;
				_end->right = nullptr;
				_end->left = nullptr;2
			}
			template <class U> Node<U>* newnode(const U& value)
			{
				Node<U> *a = _alloc.allocate(1);
				Node<U> n(value);
				_alloc.construct(a, n);
				return (a);
			}

			void	setRoot(node_pointer x) { _root = x; };

			template <class U> Node<U>* tree_min()
			{
				node_pointer tmp = _root;
				while(tmp->left)
					tmp = tmp->left;
				return (tmp);
			}

			template <class U> Node<U>* tree_next(node_pointer x)
			{
				if(x->right)
					return tree_min(x->right)
				else if(x->isThisRightC())
					x = x->parent;
				return static_cast<node_pointer>(x);
			}

			template <class U> Node<U>* tree_prev(node_pointer x)
			{
				if(x->left)
					return tree_max(x->left)
				else if(x->isThisLeftC())
					x = x->parent;
				return static_cast<node_pointer>(x);
			}

			template <class U> node_pointer search(const U& toSearch) const
			{
				node_pointer np = _root;
				while(np != nullptr)
				{
					if(np->value.first > toSearch)			//np->value.first is the first element of the ~pair~, in fact value has a value_type type, which is the alias for T that is used in pair.hpp
							np = np->left;
					else if(np->value.first < toSearch)
							np = np->right;
					else if(np->value.first == toSearch)
						return (np);
				}
				return (nullptr);
			}

			template <class U> iterator find (const U& toFind)
			{
				node_pointer np = search(toFind);
				iterator ret;
				if(np == nullptr)
					ret = (iterator)_end;
				else
					ret = (iterator)x;
				return (ret);
			}

			template <class U> const_iterator find (const U& toFind)
			{
				node_pointer np = search(toFind);
				const_iterator ret;
				if(np == nullptr)
					ret = (const_iterator)_end;
				else
					ret = (const_iterator)x;
				return (ret);
			}

			//Iterators
			iterator begin() const{ return iterator(_begin); }
			const_iterator cbegin() const{ return iterator(_begin); }
			iterator end() const{ return iterator(_end); }
			const_iterator cend() const{ return iterator(_end); }
			reverse_iterator rbegin() const{ return reverse_iterator(_end); }
			reverse_iterator rend() const{ return reverse_iterator(_begin); }
			
			//Modifiers
			void clear()
			{
				
			}
			void erase( iterator pos )
			{

			}
			void erase_rng( iterator first, iterator last )
			{

			}

			pair<iterator, bool> insert( const value_type& value )
			{

			}
			template< class InputIterator >
			void insert( InputIterator first, InputIterator last )
			{
				
			}

			//Capacity
			size_type size() const { return _size; }
            size_type max_size() const { return (_alloc.max_size()); }

			value_compare& value_comp(){ return _comp; }
			const value_compare& value_comp(){ return _comp; }
			
		protected:
			node_pointer		_root;
			node_pointer		_begin;
			node_pointer 		_end;
			allocator_type		_alloc;
			value_compare		_comp;
			size_type			_size;
	};
}
