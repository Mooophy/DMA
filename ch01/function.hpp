#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iterator>
#include <algorithm>

namespace dma {

template<typename Iter, typename Func>
class Function
{
public:
    using Value = typename std::iterator_traits<Iter>::value_type;

    Function(Iter pre_beg, Iter pre_end, Iter img_beg, Iter img_end,Func func):
        pre_begin_{pre_beg},
        pre_end_{pre_end},
        img_begin_{img_beg},
        img_end_{img_end},
        func_{std::move(func)}
    {}

    bool is_one2one()const
    {
        return true;
    }

    bool is_invertible()const
    {
        return true;
    }

    bool is_onto()const
    {
        return true;
    }

    Value inverse(Value const& val)const
    {
        return val;
    }

private:
    Iter pre_begin_;
    Iter pre_end_;
    Iter img_begin_;
    Iter img_end_;
    Func func_;
};

}//namespace
#endif // FUNCTION_HPP
