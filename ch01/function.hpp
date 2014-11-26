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
#include <stdexcept>

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
        func_{std::move(func)},
        is_onto_{do_is_onto()},
        is_one2one_{do_is_one2one()},
        is_invertible_{false}
    {
        is_invertible_  =   is_onto_ && is_one2one_;
    }

    /**
     * @brief is_one2one
     */
    bool is_one2one()const
    {
        return is_one2one();
    }

    bool is_invertible()const
    {
        return is_invertible_;
    }

    bool is_onto()const
    {
        return is_onto_;
    }

    Value inverse(Value const& val)const
    {
        return do_inverse(val);
    }

    Function& reset(Func new_func)
    {
        func_           =   std::move(new_func);
        is_onto_        =   do_is_onto();
        is_one2one_     =   do_is_one2one();
        is_invertible_  =   is_onto_ && is_one2one_;
        return *this;
    }
private:
    const Iter pre_begin_;
    const Iter pre_end_;
    const Iter img_begin_;
    const Iter img_end_;
    Func func_;
    bool is_onto_;
    bool is_one2one_;
    bool is_invertible_;

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

    bool do_is_onto()const
    {
        std::set<Value> set;
        for(auto  it = pre_begin_; it != pre_end_; ++it)
            set.insert(func_(*it));

        return std::equal(set.cbegin(), set.cend(), img_begin_);
    }

    Value do_inverse(Value const& val)const
    {
        for(auto it = pre_begin_; it != pre_end_; ++it)
            if(val == func_(*it))   return *it;
        throw std::logic_error{"not invertible."};
    }
};

}//namespace
#endif // FUNCTION_HPP
