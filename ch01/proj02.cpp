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

    }
public:
    BitString(std::string const& str) :
        data_{str}
    {
        check();
    }
    BitString(std::string && str)noexcept : data_{std::move(str)}
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
    dm::println(dm::BitString{"100"});
}
