//!
//! @author Yue Wang
//! @date   27.11.2014
//!
//! @brief  implementationn for sort algorithms, chapter 2.
//!
#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>

namespace dma {

/**
 * @brief   bubble_sort
 * @complx  O(n^2)
 */
template<typename It>
void bubble_sort(It first, It last)
{
    if(last-first < 2)  return;
    using std::swap;
    for(auto i=first; i != last-1; ++i)
        for(auto j=first; j != first+(last-1-i); ++j)
            if(*j > *(j+1)) swap(*j, *(j+1));
}

/**
 * @brief   insertion_sort
 * @complx  O(n^2)
 */
template<typename It>
void insertion_sort(It first, It last)
{
    if(last-first < 2)  return;
    for(auto i = first+1; i != last; ++i){
        auto key = *i;
        auto j = i-1;
        for(  ;  j != first-1  and  *j > key;  --j)    *(j+1)  =  *j;
        *++j = key;
    }
}

}//namespace

#endif // SORT_HPP
