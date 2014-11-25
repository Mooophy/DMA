//!
//! @author Yue Wang
//! @date   25.11.2014
//!
//! @brief  this code implemented a wrapper for function
//!

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iterator>
#include <algorithm>
#include <set>
#include <memory>

namespace dma {

/**
 * @brief The Function class
 *
 * a function wrapper provides a few features
 */
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

    /**
     * @brief is_one2one
     */
    bool is_one2one()const
    {
        return do_is_one2one();
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

    Function& reset(Func new_func)
    {
        func_ = std::move(new_func);
        return *this;
    }
private:
    const Iter pre_begin_;
    const Iter pre_end_;
    const Iter img_begin_;
    const Iter img_end_;
    Func func_;

    bool do_is_one2one()const
    {
        std::set<Value> set;
        std::vector<Value> vec;
        for(auto it = pre_begin_; it != pre_end_; ++it)
        {
            auto res = func_(*it);
            set.insert(res);
            vec.push_back(res);
        }

        return set.size() == vec.size();
    }
};

}//namespace
#endif // FUNCTION_HPP
