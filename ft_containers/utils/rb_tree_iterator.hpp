#pragma once

#include "rb_tree.hpp"
#include "iterator.hpp"

namespace ft
{
    template <class T> struct Node;
	template <class _Tp>
	struct rb_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, _Tp>
	{
		typedef	struct Node<_Tp>		iterator_value;
		typedef	iterator_value*			iterator_type;
		typedef _Tp                     value_type;
		typedef _Tp&                  	reference;
		typedef _Tp*					pointer;

		iterator_type ptr;
		public:
            explicit rb_tree_iterator(): ptr(nullptr){}
            explicit rb_tree_iterator(iterator_type x): ptr(x){}
            template <class U> rb_tree_iterator(const rb_tree_iterator<U> &copy) { *this = copy; };
			rb_tree_iterator& operator=(const rb_tree_iterator & u) { ptr = u.base(); return *this; };
			iterator_type base() const { return ptr; };
			reference operator*() const { return (*ptr).value; };
			pointer operator->() const { return &(ptr->value); };
			
			rb_tree_iterator& operator++()
			{
				if(ptr->right != nullptr)
				{
					ptr = ptr->right;
					while(ptr->left)
						ptr = ptr->left;
				}
				else
				{
					while(ptr->parent->isThisRightC())
						ptr = ptr->parent;
					ptr = ptr->parent;
				}
				return (*this);
			}
			rb_tree_iterator operator++(int)
			{
				rb_tree_iterator tmp = *this;
				++*this;
				return tmp;
			}

			rb_tree_iterator& operator--()
			{
				if(ptr->left)
				{
					ptr = ptr->left;
					while(ptr->right)
						ptr = ptr->right;
				}
				else
				{
					while(ptr->parent->isThisLeftC())
						ptr = ptr->parent;
					ptr = ptr->parent;
				}
				return(*this);
			}
			rb_tree_iterator operator--(int)
			{
				rb_tree_iterator tmp = *this;
				--*this;
				return tmp;
			}

			friend bool operator==(const rb_tree_iterator &x, const rb_tree_iterator &y) { return x.base() == y.base(); }
			friend bool operator!=(const rb_tree_iterator &x, const rb_tree_iterator &y) { return x.base() != y.base(); }
    };

	template <class T> struct rb_tree_iterator;
	template <class _Tp>
	struct const_rb_tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, _Tp>
	{
		typedef	struct Node<_Tp>		iterator_value;
		typedef	const iterator_value*	iterator_type;
		typedef _Tp                     value_type;
		typedef const _Tp&             	const_reference;
		typedef const _Tp*				const_pointer;

		iterator_type ptr;
		public:
            explicit const_rb_tree_iterator(): ptr(nullptr){}
            explicit const_rb_tree_iterator(iterator_type x): ptr(x){}
            template <class U> const_rb_tree_iterator(const const_rb_tree_iterator<U> &copy) { *this = copy; };
			template <class U> const_rb_tree_iterator(const rb_tree_iterator<U> &copy) { *this = copy; };
			
			const_rb_tree_iterator& operator=(const const_rb_tree_iterator & u) { ptr = u.base(); return *this; };
			const_rb_tree_iterator& operator=(const const_rb_tree_iterator & u) const { ptr = u.base(); return *this; };
			
			iterator_type base() const { return ptr; };

			const_reference operator*() const { return (*ptr).value; };
			const_pointer operator->() const { return &(ptr->value); };
			
			const_rb_tree_iterator& operator++()
			{
				if(ptr->right)
				{
					ptr = ptr->right;
					while(ptr->left)
						ptr = ptr->left;
				}
				else
				{
					while(ptr->parent->isThisRightC())
						ptr = ptr->parent;
					ptr = ptr->parent;
				}
				return (*this);
			}
			const_rb_tree_iterator operator++(int)
			{
				const_rb_tree_iterator tmp = *this;
				++*this;
				return tmp;
			}

			const_rb_tree_iterator& operator--()
			{
				if(ptr->left)
				{
					ptr = ptr->left;
					while(ptr->right)
						ptr = ptr->right;
				}
				else
				{
					while(ptr->parent->isThisLeftC())
						ptr = ptr->parent;
					ptr = ptr->parent;
				}
				return(*this);
			}
			const_rb_tree_iterator operator--(int)
			{
				const_rb_tree_iterator tmp = *this;
				--*this;
				return tmp;
			}

			friend bool operator==(const const_rb_tree_iterator &x, const const_rb_tree_iterator &y) { return x.base() == y.base(); }
			friend bool operator!=(const const_rb_tree_iterator &x, const const_rb_tree_iterator &y) { return x.base() != y.base(); }
	};
}