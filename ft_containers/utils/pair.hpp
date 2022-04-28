#pragma once

namespace ft
{
    template<class T1, class T2> 
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        T1 first;
        T2 second;

        pair(): first(), second() {};
        pair(const first_type& a, const second_type& b): first(a), second(b) {}
        template< class U1, class U2 >
        pair( const pair<U1, U2>& p ): first(p.first), second(p.second) {}
        ~pair()

        pair& operator=( const pair& other )
        {
            this->first = other.first;
            this->second = other.second;
            *this;
        }
    };

    //Non-member functions
    template< class T1, class T2 >
    ft::pair<T1,T2> make_pair( T1 t, T2 u ) 
    {
        return ( pair<T1,T2>(t,u) );
    }

    template< class T1, class T2 >
    bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return (lhs.first == rhs.first && lhs.second == rhs.second); }

    template< class T1, class T2 >
    bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return (lhs.first != rhs.first && lhs.second != rhs.second); }

    template< class T1, class T2 >
    bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

    template< class T1, class T2 >
    bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return !(rhs < lhs); }

    template< class T1, class T2 >
    bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return (rhs < lhs); }

    template< class T1, class T2 >
    bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ) { return !(lhs < rhs); }

}