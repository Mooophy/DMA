#include "function.hpp"
#include "../include/utilities.hpp"

int main()
{
    //! init
    using Iter          =   typename    std::vector<int>::const_iterator;
    using FuncWrapper   =               dma::Function<Iter, std::function<int(int)> >;
    std::vector<int> pre{1,2,3,4}, img{2,3,4,5};

    //! f(x) = x
    auto func1 = [](int i){  return i; };
    FuncWrapper wrapper(pre.cbegin(), pre.cend(), pre.cbegin(), pre.cend(), func1);
    dma::println(wrapper.is_invertible()?   "invertible" : "not invertible");
    auto i = wrapper.inverse(3);
    dma::println(i);

    //! f(x) = x + 1
    auto func2 = [](int i){  return i + 1; };
    FuncWrapper wrapper2(pre.cbegin(), pre.cend(), img.cbegin(), img.cend(), func2);
    auto j = wrapper2.inverse(3);
    dma::println(j);

    dma::exit();
    return 0;
}
//! @output
//!
//dma> invertible
//dma> 3
//dma> 2
//dma> exit normally
