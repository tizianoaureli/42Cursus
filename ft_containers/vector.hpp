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
//#include "utils/lexicographical_compare.hpp"

namespace ft{
    template <class T, class Allocator = std::allocator<T> >
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
                _alloc = x._alloc;
                _begin = x._begin;
                _capacity = x._capacity;
                _size = x._size;
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
            size_type size() const { return _size; }
            size_type max_size() const { return allocator.max_size() }
            void resize (size_type n, value_type val = value_type()) 
            {
                if(n < _size)
                    for(size_t i = n; i < _size; i++)
                        delete _begin[i];
                else if(n > _size && n < _capacity && !val)
                    for (size_t i = _size; i < n; i++)
                        _begin[i] = 0;
                else if(n > _size && n < _capacity)
                    for (size_t i = _size; i < n; i++)
                        _begin[i] = val;
                else if(n > _size && n > _capacity)
                {
                    try
                    {
                        reserve(n);
                        for (size_t i = _size; i < n; i++)
                            _begin[i] = val;
                    }
                    catch (std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    }                    
                }
                else if(n > _size && n > _capacity && !val)
                {
                    try
                    {
                        reserve(n);
                        for (size_t i = _size; i < n; i++)
                            _begin[i] = 0;
                    }
                    catch (std::bad_alloc& ba)
                    {
                        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
                    } 
                }
            }
            size_type capacity() const { return _capacity; }
            bool empty() const { return(_size != 0 ? 1 : 0) }
            void reserve (size_type n) 
            {
                if(n > _capacity && _begin)                       //If vector is already allocated
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
                        _capacity = n;
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
                        //_alloc.deallocate(_begin, _capacity);         //?
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
            reference operator[] (size_type n) { return(_begin[n]); }
            const_reference operator[] (size_type n) const { return(_begin[n]); }
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
                size_type new_size;
                for (tmp = first; tmp != last; ++tmp)
                    new_size++;
                if (_begin != nullptr && _capacity != 0)
                    _alloc.deallocate(_begin, _capacity);
                _capacity = new_size * 2;
                _begin = _alloc.allocate(_capacity);
                for (size_t i = 0; first != last; first++, i++)
                    _begin[i] = *first;
                _size = new_size;
            }

            void assign (size_type n, const value_type& val)
            {
                if (_size < n)
                    reserve(n);
                for(size_t i = 0; i < n; i++)
                    _begin[i] = val;
            }

            //Pushback
            void push_back (const value_type& val)
            {
                if (_size + 1 > _capacity)
                    reserve((_capacity + 1) * 2);
                _size += 1;
                _alloc.construct((_begin + _size - 1), val);
            }

            //Pop_back
            void pop_back()
            {
                _alloca.destroy(_begin + _size - 1);
                _size--;
            }

            //Insert
            //Single element
            iterator insert (iterator position, const value_type& val)
            {
                size_type new_capacity;
                if (_size + 1 > _capacity)
                    new_capacity = (_size + 1) * 2;
                pointer new_vect = _alloc.allocate(new_capacity);
                size_t i = 0;
                for ( ; i != pos - 1; i++)
                    new_vect[i] = _begin[i];
                new_vect[i++] = val;
                for ( ; i < _size; i++)
                    new_vect[i] = _begin[i - 1];
                for (size_t j = 0; j < _size; j++)
                    delete _begin[j];
                _alloc.deallocate(_begin, _capacity);
                _size++;
                if(_size > _capacity)
                {
                    _begin = _alloc.allocate(_size * 2);
                    _capacity = _size * 2;
                }
                i = 0;
                for ( ; i < _size; i++)
                    _begin[i] = new_vect[i];
                iterator it = begin();
                for (i = 0; i != position; it++)
                    i++;
                return(it);
            }

            //Fill
            void insert (iterator position, size_type n, const value_type& val)
            {
                for(size_t i = 0; i != n; i++)
                    position = insert(position, val);
            }

            //Range
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                InputIterator iter = last;
                InputIterator end = first;
                iter--;
                end--;
                for( ; it != end; it--)
                    insert(position, *it);
            }

            //Erase
            //Single element
            iterator erase (iterator position)
            {
                pointer new_vect = _alloc.allocaate(_size * 2);
                for (size_t i = 0; i < _size; i++)
                    if (i != position)
                        new_vector[i] = _begin[i];
                for (size_t i = 0; i < _size; i++)
                    delete _begin[i];
                _size--;
                _alloc.deallocate(_begin, _capacity);
                _begin = _alloc.allocate(_capacity);
                for(size_t i = 0; i < _size; i++)
                    _begin[i] = new_vect[i];
                iterator it = begin();
                for (size_t i = 0; i != position; it++)
                    i++;
                return(it);
            }

            //Range
            iterator erase (iterator first, iterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
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
            size_type       _size;                              //It represents how many elements are in the vector
            size_type       _capacity;                          //It represents how big the actual vector is
            pointer         _begin;                             //Vector that we use to do various actions
            allocator_type  _alloc;                             //Allocator that we use to allocate/deallocate/construct/etc. the vector _begin

    };

    //Non-member functions
    //Relational operators
    template <class T, class Alloc>
        bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return(lhs == rhs); }
    template <class T, class Alloc>
        bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
    template <class T, class Alloc>
        bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
    template <class T, class Alloc>
        bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
    template <class T, class Alloc>
        bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
    template <class T, class Alloc>
        bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
    
    //Swap
}