//!
//! @author Yue Wang
//! @date   25.11.2014
//!
//! @brief  proj7, chapter 1.
//!         check if one to one function
//!

#include <vector>
#include <functional>
#include "function.hpp"
#include "../include/utilities.hpp"

int main()
{
    //! init
    using Iter          =   typename    std::vector<int>::const_iterator;
    using FuncWrapper   =               dma::Function<Iter, std::function<int(int)> >;
    auto func = [](int i){  return i * i; };
    std::vector<int> v{-1, 1,2,3,4};

    //! check the first function : func
    FuncWrapper wrapper(v.cbegin(), v.cend(), v.cbegin(), v.cend(), func);
    dma::print("func : ");
    dma::println(wrapper.is_one2one()? "one to one !" : "not one to one.");

    //! check the second function : lambda
    wrapper.reset([](int i){  return i * i; });
    dma::print("this lambda : ") ;
    dma::println(wrapper.is_one2one()? "one to one !" : "not one to one.");

    dma::exit();
    return 0;
}
