#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iterator>

namespace dma {

template<typename It>
using Value = typename std::iterator_traits<It>::value_type;

/**
 * @brief find_max
 */
template<typename It>
inline It find_max(It first, It last)
{
    auto max = first;
    for(auto it = first; it != last; ++it)
        if(*max < *it) max = it;
    return max;
}

/**
 * @brief linear_search
 */
template<typename It>
inline It linear_search(It first, It last, Value<It> val)
{
    for(auto it = first; it != last; ++it)
        if(*it == val) return it;
    return last;
}

/**
 * @brief binary_search
 */
template<typename It>
It binary_search(It first, It last, Value<It> val)
{
    for(It m{}, b{first}, e{last};  b<e; (*m>val ? e : b) = m)
    {
        m = b + (e-b)/2;
        if(*m == val) return m;
    }
    return last;
}

}//namespace

#endif // SEARCH_HPP
