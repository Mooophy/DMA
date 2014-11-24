//!
//! @author Yue Wang
//! @date   22.11.2014
//!
//! proj 2.
//! Given two bit strings of length n, find the bitwise AND,
//! bitwise OR, and bitwise XOR of these strings
//!


#include <string>
#include <stdexcept>
#include "../include/dm.hpp"

namespace dm {

class BitString
{
    friend std::ostream&
    operator<<(std::ostream& os, BitString& bs)
    {
        return os << bs.data_;
    }

    friend BitString
    operator&(BitString const& lhs, BitString const& rhs)
    {
        BitString ret;
        for(auto l=lhs.cbegin(), r=rhs.cbegin(); l != lhs.cend();   ++l,++r)
            ret.push_back(((*l -'0') & (*r - '0')) + '0');

        return ret;
    }

    friend BitString
    operator|(BitString const& lhs, BitString const& rhs)
    {
        BitString ret;
        for(auto l=lhs.cbegin(), r=rhs.cbegin(); l != lhs.cend();   ++l,++r)
            ret.push_back(((*l -'0') | (*r - '0')) + '0');

        return ret;
    }

    friend BitString
    operator^(BitString const& lhs, BitString const& rhs)
    {
        BitString ret;
        for(auto l=lhs.cbegin(), r=rhs.cbegin(); l != lhs.cend();   ++l,++r)
            ret.push_back(((*l -'0') ^ (*r - '0')) + '0');

        return ret;
    }
public:

    using ConstIter = std::string::const_iterator;

    BitString() = default;

    BitString(BitString && other):
        BitString(std::move(other.data_))
    {}

    BitString(BitString const& other):
        BitString(other.data_)
    {}

    BitString(std::string const& str) :
        data_{str}
    {
        check();
    }

    BitString(std::string && str)noexcept :
        data_{std::move(str)}
    {
        check();
    }

    BitString& operator=(BitString const& other)
    {
        data_ = other.data_;
        return *this;
    }

    BitString& operator=(BitString && other)noexcept
    {
        data_ = std::move(other.data_);
        return *this;
    }

    void push_back(char c)
    {
        data_.push_back(c);
    }

    ConstIter cbegin()const
    {
        return data_.cbegin();
    }

    ConstIter cend()const
    {
        return data_.cend();
    }

private:
    std::string data_;

    void check()
    {
        for(auto c : data_)
            if(c < '0' || c > '1')
                throw std::logic_error{"only 0 and 1 are permitted."};
    }
};
}//namespace

int main()
{
    dm::BitString lhs("1010"), rhs("1111");

    auto res_of_and =   lhs & rhs;
    auto res_of_or  =   lhs | rhs;
    auto res_of_xor =   lhs ^ rhs;

    dm::println(res_of_and);
    dm::println(res_of_or);
    dm::println(res_of_xor);

    dm::exit();
    return 0;
}
//! output
//!
//1010
//1111
//0101

//exit normally
