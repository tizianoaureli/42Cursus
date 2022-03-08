#pragma once

namespace ft{
    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
        {
            for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
            {
                if(*first1 < *first2) return false;
                if(*first2 < *first1) return true;
            }
            return (first1 == last1) && (first2 != last2);
        }
    template <class InputIterator1, class InputIterator2, class Compare>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
        {
            for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
            {
                if(comp(*first1, *first2)) return false;
                if(comp(*first2, *first1)) return true;
            }
            return (first1 == last1) && (first2 != last2);
        }
    }