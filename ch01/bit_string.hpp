#ifndef BIT_STRING_HPP
#define BIT_STRING_HPP

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
    operator-(BitString const& lhs, BitString const& rhs)
    {
        BitString ret;
        for(auto l=lhs.cbegin(), r=rhs.cbegin(); l != lhs.cend();   ++l,++r)
            ret.push_back((*r - '0')? '0' : *l);

        return ret;
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
    using SizeType  = std::string::size_type;

    BitString() = default;

    BitString(SizeType sz):
        data_(sz,'0')
    {}

    BitString(BitString && other):
        BitString(std::move(other.data_))
    {}

    BitString(BitString const& other):
        BitString(other.data_)
    {}

    BitString(std::string const& str):
        data_{str}
    {
        check();
    }

    BitString(std::string && str)noexcept:
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

    /**
     * @brief operator !
     *
     * complement
     */
    BitString operator !()
    {
        auto cmpl = *this;
        for(auto& c : cmpl.data_)
            c = (c - '0')?  '0' :   '1';
        return cmpl;
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

#endif // BIT_STRING_HPP
