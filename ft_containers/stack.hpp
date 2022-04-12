#pragma once

#include "vector.hpp"
#include <stack>

namespace ft{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef Container                                container_type;
        typedef typename container_type::value_type      value_type;
        typedef typename container_type::reference       reference;
        typedef typename container_type::const_reference const_reference;
        typedef typename container_type::size_type       size_type;

    protected:
        container_type c;
    public:
        explicit stack(const container_type& cntr = container_type()) { this->c = cntr; } 
        ~stack() {}
        stack(const stack& q) : c(q.c) {}

        stack& operator=(const stack& q) { this->c = q.c; return *this; }

        //Member functions
        bool empty() const { return(this->c.empty()); }
        size_type size() const { return(this->c.size()); }
        value_type& top() { return(this->c.back()); }
        const value_type& top() const { return(this->c.back()); }
        void push(const value_type& x) { this->c.push_back(x); }
        void pop() { this->c.pop_back(); }

        friend
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return(lhs.c == rhs.c); }
		friend
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return(lhs.c > rhs.c); }
    };

    //Non-member functions
    template <class T, class Container>
    bool operator==(const stack<T, Container>& x, const stack<T, Container>& y) { return(x.c == y.c); }
    template <class T, class Container>
    bool operator< (const stack<T, Container>& x, const stack<T, Container>& y) { return(x.c < y.c); }
    template <class T, class Container>
    bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y) { return(x.c != y.c); }
    template <class T, class Container>
    bool operator> (const stack<T, Container>& x, const stack<T, Container>& y) { return(x.c > y.c); }
    template <class T, class Container>
    bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y) { return(x.c >= y.c); }
    template <class T, class Container>
    bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y) { return(x.c <= y.c); }
}