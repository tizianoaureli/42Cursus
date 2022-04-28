#pragma once

#include <memory>
#include <algorithm>
#include <list>
#include <cstring>
#include "utils/iterator.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/lexicographical_compare.hpp"

namespace ft{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef T										    value_type;
            typedef Allocator									allocator_type;
            typedef typename allocator_type::reference			reference;
            typedef typename allocator_type::const_reference	const_reference;

            typedef typename allocator_type::size_type			size_type;
            typedef typename allocator_type::difference_type	difference_type;
            typedef typename allocator_type::pointer			pointer;
            typedef typename allocator_type::const_pointer		const_pointer;
            typedef ft::base_iterator<pointer>					iterator;
            typedef ft::base_iterator<const_pointer>			const_iterator;
            typedef ft::reverse_iterator<iterator>				reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

            //Exception for ~ at ~ function
            class out_of_range : public std::out_of_range
            {
                public:
                    out_of_range(std::string mex) : std::out_of_range(mex) {};
            };

            //Constructors
            //Default
            explicit vector (const allocator_type& alloc = allocator_type()):
            _size(0),
            _capacity(0),
            _begin(nullptr),
            _alloc(alloc)
            {}

            //Fill, constructs a container with n elements, each of those are a copy of ~val~
            explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type()):
            _size(n),
            _capacity(n*2),         //It's better to give the vector a capacity two times bigger than its actual size, so that it doesn't have to re-allocate constantly.
            _begin(nullptr),
            _alloc(alloc)
            {
                _begin = _alloc.allocate(_capacity);
                for (size_t i = 0; i < n; i++)
                    _alloc.construct(&_begin[i], val);
            }

            //Range, constructs a container with as many elements as the range [first, last], each element is the equivalent of its corresponding element in the same order.
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0):
            _size(0),
            _capacity(0),
            _begin(nullptr),
            _alloc(alloc)
            {
                assign(first, last);
            }

            //Copy
            vector (const vector& x)
            {
                _capacity = x._capacity;
                _size = x._size;
                _begin = _alloc.allocate(_capacity);
                assign(x._begin, (x._begin + x._size));
            }

            //Destroyer
            ~vector()
            {
                if(_begin != nullptr)
                {
                    clear();
                    _alloc.deallocate(_begin, _capacity);
                }
            }

            //Operator=
            vector& operator= (const vector& x)
            {
                _size = x._size;
                _capacity = x._capacity;
                _begin = _alloc.allocate(_capacity);
                assign(x._begin, (x._begin + x._size));
                return *this;
            }

            //Iterators
            iterator begin() { return(iterator(_begin)); }
            const_iterator begin() const { return(iterator(_begin)); }
            iterator end() { return(iterator(_begin + _size)); }
            const_iterator end() const { return(iterator(_begin + _size)); }
            reverse_iterator rbegin() { return (reverse_iterator(end())); }
		    const_reverse_iterator rbegin() const { return (const_reverse_iterator(rend())); }
    		reverse_iterator rend() { return (reverse_iterator((begin()))); }
	    	const_reverse_iterator rend() const { return (const_reverse_iterator(rbegin())); }
            
            //Capacity
            size_type size() const { return _size; }
            size_type max_size() const { return (_alloc.max_size()); }
            void resize (size_type n, value_type val = value_type()) 
            {
                if(n >= _size)
                {
                    if(n > _capacity)
                        reserve(n);
                    if (!val)
                        val = 0;
                    for(size_t i = _size; i < n; i++)
                        _begin[i] = val;
                }
                _size = n;
            }
            size_type capacity() const { return _capacity; }
            bool empty() const { return(_size == 0); }
            void reserve (size_type n) 
            {
                if(n > _capacity && _begin)                       //If vector is already allocated
                {
                    try
                    {
                        pointer tmp = NULL;
                        tmp = _alloc.allocate(n);
                        for (size_t i = 0; i < _size; i++)
                                _alloc.construct((tmp + i), _begin[i]);
                        _alloc.deallocate(_begin, _capacity);
                        _begin = _alloc.allocate(n);
                        for (size_t i = 0; i < _size; i++)
                                _alloc.construct((_begin + i), tmp[i]);
                        _capacity = n;
                        _alloc.deallocate(tmp, n);
                    }
                    catch (std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    }
                }
                else if(n > _capacity && !_begin)                 //If vector is not allocated
                {
                    try
                    {
                        _begin = _alloc.allocate(n);
                        _capacity = n;
                    }
                    catch (std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    }
                }
            }

            //Element access
            reference operator[] (size_type n) { return(this->_begin[n]); }
            const_reference operator[] (size_type n) const { return(this->_begin[n]); }
            reference at (size_type n)
            {
                if(n >= _size)
                    throw(out_of_range("vector"));
                return (_begin[n]);
            }
            const_reference at (size_type n) const
            {
                if(n >= _size)
                    throw(out_of_range("vector"));
                return (_begin[n]);
            }
            reference front() { return(_begin[0]); }
            const_reference front() const { return(_begin[0]); }
            reference back() { return(_begin[_size - 1]); }
            const_reference back() const { return(_begin[_size - 1]); }

            //Modifiers
            //Assign
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                InputIterator tmp;
                size_type new_size = 0;
                for (tmp = first; tmp != last; ++tmp)
                    new_size++;
                if (_begin != nullptr && _capacity != 0)
                    _alloc.deallocate(_begin, _capacity);
                _capacity = new_size * 2;
                _begin = _alloc.allocate(_capacity);
                for (size_t i = 0; first != last; first++, i++)
                    _alloc.construct(&_begin[i], *first);
                _size = new_size;
            }

            void assign (size_type n, const value_type& val)
            {
                if (_size < n)
                    reserve(n * 2);
                _size = n;
                for(size_t i = 0; i < n; i++)
                    _begin[i] = val;
            }

            //Pushback
            void push_back (const value_type& val)
            {
                if (_size + 1 >= _capacity)
                    reserve((_capacity + 1) * 2);
                _size ++;
                _alloc.construct((_begin + _size - 1), val);            
                _begin[_size - 1] = val;
            }

            //Pop_back
            void pop_back()
            {
                _size--;
            }

            //Insert
            //Single element
            iterator insert (iterator position, const value_type& val)
            {
                size_type pos = 0;
                for(iterator it = begin(); it != position; it++)
                    pos++;
                if((_size + 1) > _capacity)
                    reserve((_capacity + 1) * 2);
                _size++;
                size_type fin = _size;
                for( ; fin != pos && fin != (pos - 1); fin--)
                    _begin[fin - 1] = _begin[fin - 2];
                _begin[pos] = val;
                size_t index = 0;
                iterator i = begin();
                for ( ; index != pos; i++)
                    index++;
                return(i);
            }

            //Fill
            void insert (iterator position, size_type n, const value_type& val)
            {
                size_t pos = 0;
                for (iterator it = begin(); it != position; ++it)
                    pos++;
                if (_size + n > _capacity)
                    reserve((_size + n) *2);
                _size += n;
                size_t index = _size;
                while (index > pos && (index - n) > pos)
                {
                    _begin[index - 1] = _begin[index - n - 1];
                    index--;
                }
                size_t j = 0;
                while (j < n)
                {
                    _begin[pos] = val;
                    pos++;
                    j++;
                }
            }

            //Range
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                size_t range = 0;
                for (InputIterator i = first; i != last; ++i)
                    range++;
                size_t pos = 0;
                for (iterator it = begin(); it != position; ++it)
                    pos++;
                if (_size + range > _capacity)
                    reserve((_size + range)*2);
                _size += range;
                size_t index = _size;
                while (index > pos && (index - range) > pos)
                {
                    _begin[index - 1] = _begin[index - range - 1];
                    index--;
                }
                for(; first != last; first++, pos++)
                    _begin[pos] = *first;
            }

            //Erase
            //Single element
            iterator erase (iterator position)
            {
                size_type pos = 0;
                for(iterator it = begin(); it != position; ++it)
                    pos++;
                _alloc.destroy(_begin + pos);
                _size--;
                for ( ; pos < _size; pos++)
                    _begin[pos] = _begin[pos + 1];
                return (position);	
            }

            //Range
            iterator erase (iterator first, iterator last)
            {
                size_t i = 0;
                iterator x = first;
                for (iterator it = first; it != last; it++)
                    i++;
                while(i > 0)
                {
                    erase(x);
                    i--;
                }
                return(first);
            }

            //Swap
            void swap (vector& x)
            {
                std::swap(this->_size, x._size);
                std::swap(this->_capacity, x._capacity);
                std::swap(this->_begin, x._begin);
                std::swap(this->_alloc, x._alloc);
            }

            //Clear
            void clear()
            {
                this->_size = 0;
            }

            //Get_allocator
            allocator_type get_allocator() const { return this->_alloc; }
        protected:
            size_t          _size;                              //It represents how many elements are in the vector
            size_t          _capacity;                          //It represents how big the actual vector is
            pointer         _begin;                             //Vector that we use to do various actions
            allocator_type  _alloc;                             //Allocator that we use to allocate/deallocate/construct/etc. the vector _begin

    };

    //Non-member functions
    //Relational operators
    template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
	{
		return (!(lhs > rhs) && !(lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){ return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}
		
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) 
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));	
	}
		
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
    
    //Swap
    template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}