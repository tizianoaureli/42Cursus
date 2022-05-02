#pragma once

#include "utils/iterator.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/pair.hpp"
#include "utils/rb_tree.hpp"

namespace ft
{
	template <class _Key, class _CP, class _Compare >
	class _map_value_compare : private _Compare
	{
		public:
			_map_value_compare() : _Compare() {}
			_map_value_compare(_Compare c) : _Compare(c) {}
			const _Compare& key_comp() const {return *this;}
			bool operator()(const _CP& _x, const _CP& _y) const
				{return static_cast<const _Compare&>(*this)(_x.first, _y.first);}
			bool operator()(const _CP& _x, const _Key& _y) const
				{return static_cast<const _Compare&>(*this)(_x.first, _y);}
			bool operator()(const _Key& _x, const _CP& _y) const
				{return static_cast<const _Compare&>(*this)(_x, _y.first);}
			void swap(_map_value_compare&_y)
			{
				std::swap(static_cast<_Compare&>(*this), static_cast<_Compare&>(_y));
			}
	};

	template <class Key,
		 class T, 
		 class _Compare = std::less<Key>,
		 class Allocator = std::allocator<ft::pair<const Key, T > >
		 >class map
	{
	public:
		typedef Key                                      			key_type;
		typedef T                                        			mapped_type;
		typedef pair<const key_type, mapped_type>        			value_type;
		typedef _Compare                                  			key_compare;
		typedef Allocator                                			allocator_type;
		typedef typename allocator_type::reference       			reference;
		typedef typename allocator_type::const_reference 			const_reference;
		typedef typename allocator_type::pointer         			pointer;
		typedef typename allocator_type::const_pointer   			const_pointer;
		typedef typename allocator_type::size_type       			size_type;
		typedef typename allocator_type::difference_type 			difference_type;


		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
				friend class map;
			protected:
				key_compare comp;
				value_compare(key_compare c) : comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
		}; //value compare

		typedef ft::rb_tree_iterator<value_type>						iterator;
		typedef ft::const_rb_tree_iterator<value_type>					const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::const_reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef _map_value_compare<key_type, value_type, key_compare> 	_vc;
		typedef	ft::RBTree<value_type, _vc>								tree;
	
		//costruttori
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(),
			  _alloc(alloc),
			  _comp(comp)
		{
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(),
			  _alloc(alloc),
			  _comp(comp)
		{
			insert(first, last);
		}
		map (const map& x)
		{
			*this = x;
		} 
		~map()
		{
		}

		map& operator= (const map& x)
		{
			_tree = x._tree;
			return *this;
		}
		//Iterators
		iterator 		begin()	{ return (iterator)_tree.begin(); }
		const_iterator 	begin() const { return (const_iterator)_tree.cbegin(); }
		reverse_iterator 		rbegin() { return (reverse_iterator(_tree.end())); }
		const_reverse_iterator 	rbegin() const { return (const_reverse_iterator(_tree.cend())); }

		iterator 		end(){	return (iterator)_tree.end();}
		const_iterator 	end()   const {	return (const_iterator)_tree.cend();}
		reverse_iterator 		rend() 	{ return (reverse_iterator(_tree.begin())); }
		const_reverse_iterator	rend()   const { return (const_reverse_iterator(_tree.cbegin())); }

		//Capacity
		bool      empty()    const { return _tree.size() == 0; }
		size_type size()     const { return _tree.size(); }
		size_type max_size() const { return _tree.max_size(); }

		//Element access
		mapped_type& 		operator[](const key_type& k)
		{
			iterator i = find(k);
			if (i != end())
				return i->second;
			std::allocator <mapped_type>T_alloc;
			mapped_type toInsert;
			T_alloc.construct(&toInsert);
			pair<key_type, mapped_type> aPair = ft::make_pair(k, toInsert);
			T_alloc.destroy(&toInsert);
			return _tree.insert(aPair).first->second;
		}

		//Modifiers
		void					clear()	{ return _tree.clear(); }

		pair<iterator, bool>	insert(const value_type& value) { return _tree.insert(value); }
		iterator				insert(iterator hint, const value_type& value) { return _tree.insert(hint, value); }
		template< class InputIterator >
		void					insert( InputIterator first, InputIterator last )
		{
			for( ; first != last; ++first)
				insert(*first);
		}

		void					erase( iterator pos ) { _tree.erase(pos); }
		void 					erase( iterator first, iterator last ) { _tree.erase_rng(first, last); }
		size_type 				erase( const key_type& key ) { return _tree.erase_key(key); }

		void 					swap (map& x) { return _tree.swap(x._tree); }
		
		//Map Operations
		size_type				count( const key_type& key ) const { return _tree.count(key); }

		iterator				find( const key_type& key ) { return _tree.find(key); }
		const_iterator			find( const key_type& key ) const { return _tree.find(key); }
		
		std::pair<iterator,iterator> 				equal_range( const key_type& key ) { return _tree.equal_range(key); }
		std::pair<const_iterator,const_iterator> 	equal_range( const key_type& key ) const { return _tree.equal_range(key); }

		iterator 				lower_bound( const key_type& key ) { return _tree.lower_bound(key); }
		const_iterator 			lower_bound( const key_type& key ) const { return _tree.lower_bound(key); }

		iterator 				upper_bound( const key_type& key ) { return _tree.upper_bound(key); }
		const_iterator 			upper_bound( const key_type& key ) const { return _tree.upper_bound(key); }

		//Observers
		key_compare 			key_comp() const { return _tree.value_comp().key_comp(); }
		value_compare 			value_comp() const { return value_compare(_tree.value_comp().key_comp()); }

		void print(){_tree._print_tree();};
	protected:
		tree			_tree;
		allocator_type	_alloc;
		key_compare 	_comp;
	};
	template <class Key, class T, class Compare, class Allocator>
	bool
	operator< (const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
	{
    	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class T, class Compare, class Allocator>
	bool
	operator==(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y)
	{
   		return x.size() == y.size() && !(x<y) && !(y<x);
	}


	template <class Key, class T, class Compare, class Allocator>
	bool
	operator!=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y)
	{
   		return !(x == y);
	}		

	template <class Key, class T, class Compare, class Allocator>
	bool
	operator> (const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y)
	{
		return (y < x);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool
	operator>=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y)
	{
		return !(x < y);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool
	operator<=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y)
	{
		return !(y < x);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) { return x.swap(y); }
}