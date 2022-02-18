#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <list>
#include <cstring>
#include <new>
#include <stdexcept>
#include "utils/iterator.hpp"
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/lexicographical_compare.hpp"

namespace ft{
    template <class T, class Allocator = allocator<T> >
    class vector
    {
        public:
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef ft::base_iterator<iterator>                 iterator;
            typedef ft::base_iterator<const_iterator>           const_iterator;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

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
                    _begin[i] = val;
            }

            //Range, constructs a container with as many elements as the range [first, last], each element is the equivalent of its corresponding element in the same order.
            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type()):
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
                *this = x;
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
                this->_alloc = x._alloc;
                this->_begin = x._begin;
                this->_capacity = x._capacity;
                this->_size = x._size;
                return(*this);
            }

            //Iterators
            iterator begin() { return(iterator(_begin)); }
            const_iterator begin() const { return(iterator(_begin)); }
            iterator end() { return(iterator(_begin + _size)); }
            const_iterator end() const { return(iterator(_begin + _size)); }
            reverse_iterator rbegin() { return(reverse_iterator(_begin + _size)); }
            const_reverse_iterator rbegin() const { return(reverse_iterator(_begin + _size)); }
            reverse_iterator rend() { return(reverse_iterator(_begin)); }
            const_reverse_iterator rend() const { return(reverse_iterator(_begin)); }

            //Capacity
            size_type size() const { return this->_size; }
            size_type max_size() const { return allocator.max_size() }
            void resize (size_type n, value_type val = value_type()) 
            {
                if(n < this->_size)
                    for(size_t i = n; i < this->_size; i++)
                        delete _begin[i];
                else if(n > this->_size && n < this->_capacity && !val)
                    for (size_t i = this->_size; i < n; i++)
                        _begin[i] = 0;
                else if(n > this->_size && n < this->_capacity)
                    for (size_t i = this->_size; i < n; i++)
                        _begin[i] = val;
                else if(n > this->_size && n > this->_capacity)
                {
                    try
                    {
                        reserve(n);
                        for (size_t i = this->_size; i < n; i++)
                            _begin[i] = val;
                    }
                    catch (std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    }                    
                }
                else if(n > this->_size && n > this->_capacity && !val)
                {
                    try
                    {
                        reserve(n);
                        for (size_t i = this->_size; i < n; i++)
                            _begin[i] = 0;
                    }
                    catch (std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    } 
                }
            }
            size_type capacity() const { return this->_capacity; }
            bool empty() const { return(this->_size != 0 ? 1 : 0) }
            void reserve (size_type n) 
            {
                if(n > this->_capacity && _begin)                       //If vector is already allocated
                {
                    try
                    {
                        pointer tmp = NULL;
                        tmp = _alloc.allocate(n);
                        for(size_t i = 0; i < _size; i++)
                            tmp = _alloc.construct(tmp[i], _begin[i]);
                        for(size_t i = 0; i < _size; i++)
                            delete _begin[i];
                        _alloc.deallocate(_begin, _capacity);
                        _begin = _alloc.allocate(n);
                        for(size_t i = 0; i < _size; i++)
                            _begin = _alloc.construct(_begin[i], tmp[i]);
                        this->_capacity = n;
                    }
                    catch (std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    }
                }
                else if(n > this->_capacity && !_begin)                 //If vector is not allocated
                {
                    try
                    {
                        _alloc.deallocate(_begin, _capacity);
                        _begin = _alloc.allocate(n);
                        this->_capacity = n;
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
            reference front() { return(this->_begin[0]); }
            const_reference front() const { return(this->_begin[0]); }
            reference back() { return(this->_begin[this->_size - 1]); }
            const_reference back() const { return(this->_begin[this->_size - 1]); }

            //Modifiers
            //Assign
            template <class InputIterator>
             void assign (InputIterator first, InputIterator last)
             {
                 
             }

        protected:
            size_type       _size;
            size_type       _capacity;
            pointer         _begin;
            allocator_type  _alloc;

    }
}