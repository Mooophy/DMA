//!
//! @author Yue Wang
//! @date   22.11.2014
//!
//! @brief  implementationn for project 5, chapter 1, DMA.
//!
#include <vector>
#include <algorithm>
#include <iostream>
#include "../include/utilities.hpp"

namespace dma {

class MultiSet
{
    friend std::ostream&
    operator <<(std::ostream& os, MultiSet const& rhs)
    {
        for(auto elem : rhs.data_)  os << elem << " ";
        return os;
    }

    friend MultiSet
    operator|(MultiSet const& lhs, MultiSet const& rhs) //union
    {
        MultiSet ret;

        for(auto l = lhs.data_.cbegin(), r = rhs.data_.cbegin();
            l != lhs.data_.cend();
            ++l, ++r)
            ret.data_.push_back(std::max(*l,*r));

        return ret;
    }

    friend MultiSet
    operator&(MultiSet const& lhs, MultiSet const& rhs) //intersection
    {
        MultiSet ret;

        for(auto l = lhs.data_.cbegin(), r = rhs.data_.cbegin();
            l != lhs.data_.cend();
            ++l, ++r)
            ret.data_.push_back(std::min(*l,*r));

        return ret;
    }

    friend MultiSet
    operator-(MultiSet const& lhs, MultiSet const& rhs) //difference
    {
        MultiSet ret;

        for(auto l = lhs.data_.cbegin(), r = rhs.data_.cbegin();
            l != lhs.data_.cend();
            ++l, ++r)
            ret.data_.push_back(*l<*r ? 0 : (*l - *r));

        return ret;
    }

    friend MultiSet
    operator+(MultiSet const& lhs, MultiSet const& rhs) //difference
    {
        MultiSet ret;

        for(auto l = lhs.data_.cbegin(), r = rhs.data_.cbegin();
            l != lhs.data_.cend();
            ++l, ++r)
            ret.data_.push_back(*l + *r);

        return ret;
    }
public:
    using SizeType = typename std::vector<std::size_t>::size_type;

    MultiSet():
        data_{}
    {}

    MultiSet(SizeType sz):
       data_(sz)
    {}

    MultiSet(std::vector<std::size_t> && v):
        data_(std::move(v))
    {}

private:
    std::vector<std::size_t> data_;
};
}//namespace

int main()
{
    using V = std::vector<std::size_t>;

    dma::MultiSet lhs(V({3,2,4}));
    dma::MultiSet rhs(V({1,5,6}));
    dma::println(lhs | rhs); //union
    dma::println(lhs & rhs); //intersection
    dma::println(lhs - rhs); //difference
    dma::println(lhs + rhs); //sum

    return 0;
}
//! output
//!
//3 5 6
//1 2 4
//2 0 0
//4 7 10
