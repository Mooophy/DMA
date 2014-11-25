//!
//! @author Yue Wang
//! @date   24.11.2014
//!
//! proj06 ch01 DMA.
//!

#include <iostream>
#include <vector>
#include "../include/dm.hpp"

namespace dm {

using Element = std::pair<std::string, double>;

class FuzzySet
{
    friend std::ostream&
    operator<<(std::ostream& os, FuzzySet const& rhs)
    {
        for(auto const& e : rhs.data_)
            os << e.first << " " << e.second << std::endl;
        return os;
    }

    friend FuzzySet
    operator|(FuzzySet const& lhs, FuzzySet const& rhs)     //union
    {
        FuzzySet ret;
        for(auto l = lhs.data_.cbegin(), r = rhs.data_.cbegin();
            l != lhs.data_.cend();
            ++l, ++r)
            ret.data_.push_back({l->first, std::max(l->second, r->second)});

        return ret;
    }

    friend FuzzySet
    operator&(FuzzySet const& lhs, FuzzySet const& rhs)     //intersection
    {
        FuzzySet ret;
        for(auto l = lhs.data_.cbegin(), r = rhs.data_.cbegin();
            l != lhs.data_.cend();
            ++l, ++r)
            ret.data_.push_back({l->first, std::min(l->second, r->second)});

        return ret;
    }
public:
    FuzzySet():
        data_{}
    {}

    FuzzySet(std::vector<Element> const& v):
        data_(v)
    {}

    FuzzySet(std::vector<Element>&& v):
        data_(std::move(v))
    {}

    FuzzySet operator!()const   //complement
    {
        FuzzySet ret = *this;
        for(auto& elem : ret.data_)     elem.second = (1.0 - elem.second);
        return ret;
    }

private:
    std::vector<Element> data_;
};
}//namespace

int main()
{
    using V = std::vector<dm::Element>;
    V lhs = {
        {"moophy", 0.2},
        {"alan",0.9},
        {"google",0.7}
    };

    V rhs = {
        {"moophy", 0.1},
        {"alan",0.2},
        {"google",0.4}
    };

    dm::FuzzySet A(lhs), B(rhs);
    dm::println(!A);
    dm::println(A | B);
    dm::println(A & B);

    return 0;
}


