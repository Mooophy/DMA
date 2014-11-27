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

template<typename It>
void bubble_sort(It first, It last)
{
    if(last-first < 2 ) return;

    using std::swap;
    for(auto i=first; i != last-1; ++i)
        for(auto j=first; j != first+(last-1-i); ++j)
            if(*j > *(j+1)) swap(*j, *(j+1));
}

}//namespace

#endif // SORT_HPP
