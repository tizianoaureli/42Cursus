#pragma once

#include <memory>
#include <functional>
#include <utility>
#include <iostream>
#include <string>
#include <exception>
#include "utils/rb_tree.hpp"

namespace ft
{
    template <class _Key, class _CP, class _Compare >
	class _map_value_compare : private _Compare
	{
        public:
            _map_value_compare() : _Compare() {}
            _map_value_compare(_Compare c) : _Compare(c) {}
            const _Compare& key_comp() const { return *this; }
            bool operator()(const _CP& __x, const _CP& __y) const
                { return static_cast<const _Compare&>(*this)(__x.first, __y.first); }
            bool operator()(const _CP& __x, const _Key& __y) const
                { return static_cast<const _Compare&>(*this)(__x.first, __y); }
            bool operator()(const _Key& __x, const _CP& __y) const
                { return static_cast<const _Compare&>(*this)(__X, __y.first); }
            void swap(_map_value_compare&__y)
                { std::swap(static_cast<_Compare&>(*this), static_cast<_Compare&>(__y)); }
    };

    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
    class map
    {
        private:
            
        public:
            typedef Key                                      			key_type;
			typedef T                                        			mapped_type;
			typedef pair<const key_type, mapped_type>   				value_type;
			typedef Compare                                  			key_compare;
			typedef Allocator                                			allocator_type;
			typedef value_type&       									reference;
			typedef const value_type&     								const_reference;
			typedef typename ft::tree_iterator<value_type>				iterator;
			typedef typename ft::const_tree_iterator<value_type>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::const_reverse_iterator<const_iterator>	const_reverse_iterator;

    };
}