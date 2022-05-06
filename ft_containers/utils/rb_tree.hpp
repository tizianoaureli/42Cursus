#pragma once

#include <iostream>
#include <memory>
#include "rb_tree_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"

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
		typedef	T											value_type;
		typedef size_t  									size_type;
		typedef value_type*									pointer;
		typedef	value_type	const * 						const_pointer;
		typedef value_type&									reference;
		typedef	value_type	const & 						const_reference;
		Node		*left;
		Node		*right;
		Node		*parent;
		bool		color;
		value_type	value;

		Node(const_reference val=value_type()):
			left(nullptr), right(nullptr), parent(nullptr),  color(RED), value(val){};
		Node(Node const &copy):
			left(nullptr), right(nullptr), parent(nullptr), color(RED), value(copy.value){};
		bool	isLeft() const { return (parent && this == parent->left); };
		bool	isRight() const { return (parent && this == parent->right); };
		bool 	is_black() { return !color; };
		Node	*grandparent() { return (parent ? (parent->parent ? parent->parent : nullptr) : nullptr); };
		Node	*uncle() {
			if (grandparent() != nullptr && parent->isLeft())
				return (grandparent()->right);
			if (grandparent() != nullptr && parent->isRight())
				return (grandparent()->left);
			return (nullptr);
		};
		Node	*sibling() {
			if (isRight() && parent->left)
				return (parent->left);
			if (isLeft() && parent->right)
				return (parent->right);
			return (nullptr);
		}
	};
	template <typename T, class Compare = std::less<T>, class Allocator = std::allocator<Node<T> > >
	class RBTree
	{
		public:
			typedef T											value_type;
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference       	reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer         	pointer;
			typedef typename allocator_type::const_pointer   	const_pointer;
			typedef typename allocator_type::size_type       	size_type;
			typedef typename allocator_type::difference_type 	difference_type;
			typedef ft::rb_tree_iterator<T>						iterator;
			typedef ft::const_rb_tree_iterator<T>				const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::const_reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	Node<T>* 									node_pointer;

			RBTree(const value_compare& comp = value_compare(), const allocator_type& alloc = allocator_type()):
			_size(0), _alloc(alloc), _comp(comp){
				_begin = nullptr;
				_end = _alloc.allocate(1);
				_end->color = BLACK;
				_end->left = nullptr;
				_end->right = nullptr;
				_end->parent = nullptr;
				_root = nullptr;
				_begin = _end;
			}
			RBTree(RBTree &copy) { *this = copy; }
			RBTree & operator=(const RBTree &other)
			{
				if(_size != 0)
				 	clear();
				_comp = other.value_comp();
				_alloc = other._alloc;
				insert(other.begin(), other.end());
				return *this;
			}
			~RBTree()
			{
				/*if (size() != 0)
					erase_range(begin(), end());*/
				_alloc.deallocate(_end, 1);
			}
			size_type 		max_size() 	const { return (_alloc.max_size()); };
			iterator		begin() 	const { return iterator(_begin); };
			const_iterator	cbegin() 	const { return const_iterator(_begin); };
			iterator		end() 		const { return iterator(_end); };
			const_iterator	cend() 		const { return const_iterator(_end); };

			reverse_iterator	rbegin() const { return reverse_iterator(end()); }
			reverse_iterator	rend() const { return reverse_iterator(begin()); }
			size_type	size() const { return (_size); };
			void		setBegin() {
				node_pointer tmp = _root;
				while (tmp->left)
					tmp = tmp->left;
				_begin = tmp;
			};
			void		setEnd() {
				node_pointer tmp = _root;
				while (tmp->right && tmp->right != _end)
					tmp = tmp->right;
				tmp->right = _end;
				_end->parent = tmp;
				_end->right = nullptr;
				_end->left = nullptr;
			};
			void		setRoot(node_pointer x) { _root = x; };
			template<class U>
			Node<U>*	newnode(const U& value)
			{
				Node<U> *a = _alloc.allocate(1);
				Node<U> n(value);
				_alloc.construct(a, n);
				return (a);
			}
			template <class U>
			iterator find (const U& k)
			{
				node_pointer x = search(k);
				iterator ret;
				if (x == nullptr)
					ret = (iterator)_end;
				else
					ret = (iterator)x;
				return(ret);
			}

			template <class U>
			const_iterator find	(const U& k) const
			{
				node_pointer x = search(k);
				const_iterator ret;
				if (x == nullptr)
					ret = (const_iterator)_end;
				else
					ret = (const_iterator)x;
				return(ret);
			}

			node_pointer getRoot() {return _root;}
			value_compare& value_comp() 		{ return _comp; }
			const	value_compare& value_comp() const 	{ return _comp; }
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)//range (3)
			{
				for (InputIterator it = first; it != last; it++)
					insert(*it);
			}

			pair<iterator,bool>	insert(const value_type& val)
			{
				if (search(val.first) != nullptr )
					return (ft::make_pair<iterator, bool>((iterator)search(val.first), false));
				node_pointer add = newnode(val);
				node_pointer y = nullptr;
				node_pointer x = _root;
				while (x != nullptr && x != _end)
				{
					y = x;
					if (value_comp()(add->value, x->value))
						x = x->left;
					else
						x = x->right;
				}
				add->parent = y;
				if (y == nullptr)
					setRoot(add);
				else if (value_comp()(add->value, y->value))
					y->left = add;
				else
					y->right = add;
				insertbalance_1(add);
				setBegin();
				setEnd();
				this->_size++;
				return (ft::make_pair<iterator, bool>((iterator)add, true));
			}
			void		insertbalance_1(node_pointer z){
				if (z->parent == nullptr)
					z->color = BLACK;
				else
					insertbalance_2(z);
			}
			void		insertbalance_2(node_pointer z){
				if (z->parent->color == BLACK)
					return ;
				else
					insertbalance_3(z);
			}
			void		insertbalance_3(node_pointer z){
				if (z->uncle() != nullptr && z->uncle()->color == RED)
				{
					z->parent->color = BLACK;
					z->uncle()->color = BLACK;
					z->grandparent()->color = RED;
					insertbalance_1(z->grandparent());
				}
				else
					insertbalance_4(z);
			}
			void		insertbalance_4(node_pointer z){
				if (z == z->parent->right && z->parent == z->grandparent()->left)
				{
					left_rotate(z->parent);
					z = z->left;
				}
				else if (z == z->parent->left && z->parent == z->grandparent()->right)
				{
					right_rotate(z->parent);
					z = z->right;
				}
				else
					insertbalance_5(z);
			}
			void		insertbalance_5(node_pointer z)
			{
				z->parent->color = BLACK;
				z->grandparent()->color = RED;
				if (z == z->parent->left && z->parent == z->grandparent()->left)
					right_rotate(z->grandparent());
				else
					left_rotate(z->grandparent());
			}

			void		left_rotate(node_pointer x)
			{
				node_pointer y = x->right;
				x->right = y->left;
				if (y->left != nullptr)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					setRoot(y);
				else {
					if (x->isLeft())
						x->parent->left = y;
					else
						x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}
			void		right_rotate(node_pointer x)
			{
				node_pointer y = x->left;
				x->left = y->right;
				if (y->right != _end && y->right != nullptr)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					setRoot(y);
				else{
					if (x->isLeft())
						x->parent->left = y;
					else
						x->parent->right = y;
				}
				y->right = x;
				x->parent = y;
			}

			template<class U>
			node_pointer	search(const U& val) const
			{
				node_pointer x = _root;
				while (x != nullptr)
				{
					if (val < x->value.first)
						x = x->left;
					else if (val == x->value.first)
						return (x);
					else
						x = x->right;
				}
				return (x);
			}
			
			void clear()
			{
				erase_range(begin(), end());
				_size = 0;
				_begin = _end;
			}
			void erase_range(iterator first, iterator last)
			{
				iterator tmp;
				while(first != last)
				{
					tmp = first;
					if(first++ != last)
						erase(tmp);
				}
			}
			void swap(RBTree& swappo)
			{
				std::swap(_begin, swappo._begin);
				std::swap(_end, swappo._end);
				std::swap(_alloc, swappo._alloc);
				std::swap(_comp, swappo._comp);
				std::swap(_size, swappo._size);
			}

			void erase(iterator __p)
			{
				pointer __np = __p.base();
				__remove_node_nodeptr(__np);
				_alloc.deallocate(__p.base(), 1);
				if (_size > 0)
					setEnd();
			}
			void	find_new_root(node_pointer x) 
			{
				while (x->parent != nullptr)
					x = x->parent;
				_root = x;
			}
			iterator __remove_node_nodeptr(pointer __ptr)
			{
				iterator __r(__ptr);
				++__r;
				if (begin().base() == __ptr)
					_begin = __r.base();
				find_new_root(__ptr);
				--_size;
				tree_remove(_root, static_cast<node_pointer>(__ptr));
				find_new_root(_begin);
				
				return __r;
			}

			template <class NodePtr>
			NodePtr tree_min(NodePtr x)
			{
				while (x->left != nullptr)
					x = x->left;
				return x;
			}
			template <class NodePtr>
			NodePtr next_iter(NodePtr x)
			{
				if (x->right != nullptr && x->right != _end)
					return tree_min(x->right);
				while (!is_left_child(x))
					x = x->parent;
				return static_cast< NodePtr>(x->parent);
			}

			template <class NodePtr>
			bool 
			is_left_child(NodePtr x)
			{
				if (x->parent == nullptr || x == x->parent->left || (x->parent->left == nullptr && x != x->parent->right && x->parent->right != nullptr) )
					return true;
				return false;
			}
			template <class NodePtr>
			void tree_remove(NodePtr root, NodePtr z)
			{
				NodePtr y = (z->left == nullptr || (z->right == nullptr) || z->right == _end) ? z : next_iter(z);
				NodePtr x = y->left != nullptr ? y->left : y->right;
				NodePtr w = nullptr;
				if (x != nullptr)
					x->parent = y->parent;
				if (is_left_child(y))
				{
					if (root != y)
						y->parent->left = x;
					if (y != root)
						w = y->parent->right;
					else
						root = x;
				}
				else
				{
					y->parent->right = x;
					w = y->parent->left;
				}
				bool removed_black = y->is_black();
				if (y != z)
				{
					y->parent = z->parent;
					if (is_left_child(z))
					{
						if (root == z)
							root = y;
						else
							y->parent->left = y;
					}
					else if (z->isRight())
						y->parent->right = y;
					y->left = z->left;
					y->left->parent = y;
					y->right = z->right;
					if (y->right != nullptr && y->right != _end)
						y->right->parent = y;
					y->color = z->color;
				}
				if (removed_black && root != nullptr)
				{
					if (x != nullptr)
						x->color = false;
					else
					{
						while (true)
						{
							if (!is_left_child(w))
							{
								if (!w->is_black())
								{
									w->color = false;
									w->parent->color = true;
									left_rotate(w->parent);
									if (root == w->left)
										root = w;
									w = w->left->right;
								}
								if (w && (w->left == nullptr || w->left->is_black()) && (w->right == nullptr || w->right->is_black()))
								{
									w->color = true;
									x = w->parent;
									if (x == root || !x->is_black())
									{
										x->color = false;
										break;
									}
									w = is_left_child(x) ? x->parent->right : x->parent->left;
								}
								else
								{
									if (w && (w->right == nullptr || w->right->is_black()))
									{
										w->left->color = false;
										w->color = true;
										right_rotate(w);
										w = w->parent;
									}
									if(w)
									{
										w->color = w->parent->color;
										w->parent->color = false;
										w->right->color = false;
										left_rotate(w->parent);
									}
									break;
								}
							}
							else
							{
								if (!w->is_black())
								{
									w->color = false;
									w->parent->color = true;
									right_rotate(w->parent);
									if (root == w->right)
										root = w;
									w = w->right->left;
								}
								if ((w->left  == nullptr || w->left->is_black()) &&
									(w->right == nullptr || w->right->is_black()))
								{
									w->color = true;
									x = w->parent;
									if (!x->is_black() || x == root)
									{
										x->color = false;
										break;
									}
									w = is_left_child(x) ? x->parent->right : x->parent->left;
								}
								else
								{
									if (w->left == nullptr || w->left->is_black())
									{
										w->right->color = false;
										w->color = true;
										left_rotate(w);
										w = w->parent;
									}
									w->color = w->parent->color;
									w->parent->color = false;
									w->left->color = false;
									right_rotate(w->parent);
									break;
								}
							}
						}
					}
				}
			}
			void _print_tree()
			{
				iterator i = begin();
				std::cout << "\n\033[0;31m********************\033[0;37m\n";
				if (_size == 0)
					std::cout << "\033[33m" << "Mappa Vuota\n";
				else
				{
					std::cout << "\033[33m" << "ALBERO\n" << "\033[0;37m";
					while (i != end())
					{
						if (i.base() != _root)
						{
							if (i.base()->is_black())
								std::cout << "\033[0;31m" << i.base()->value.first << "\033[0;37m -> parent = " << i.base()->parent->value.first << std::endl;
							else
								std::cout << i.base()->value.first << " -> parent = " << i.base()->parent->value.first << std::endl;
						}
						else
							std::cout << "ROOT => " << i.base()->value.first <<  std::endl;
						i++;
					}
				std::cout << "\033[0;31m********************\033[0;37m\n";
				std::cout << "Size: " << this->size() <<"\n";
				std::cout << "Begin: " << begin().base()->value.first <<"\n";
				std::cout << "end: " << end().base()->value.first <<"\n";
				std::cout << "end->parent: " << _end->parent->value.first <<"\n";
				std::cout << "Root: " << _root->value.first <<"\n";
				}
				std::cout << "\033[0;31m********************\033[0;37m\n";
			}
		protected:
			node_pointer	_root;
			node_pointer	_begin;
			node_pointer	_end;
			size_type		_size;
			allocator_type	_alloc;
			value_compare	_comp;
	};
}
