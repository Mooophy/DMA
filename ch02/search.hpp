#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iterator>

namespace dma {

template<typename T>
using Value = typename std::iterator_traits<T>::value_type;

template<typename It>
inline It find_max(It first, It last)
{
    auto max = first;
    for(auto it = first; it != last; ++it)  if(*max < *it) max = it;
    return max;
}

template<typename It>
inline It linear_search(It first, It last, Value<It> val)
{
    for(auto it = first; it != last; ++it)  if(*it == val) return it;
    return last;
}

}//namespace

#endif // SEARCH_HPP
