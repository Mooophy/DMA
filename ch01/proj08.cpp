//!
//! @author Yue wang
//! @date   24.11.2014
//!
//! proj 8 ch1
//! Given a function check if is it onto
//!
//!

#include "function.hpp"
#include "../include/utilities.hpp"

int main()
{
    //! init
    using Iter          =   typename    std::vector<int>::const_iterator;
    using FuncWrapper   =               dma::Function<Iter, std::function<int(int)> >;
    std::vector<int> v{-1, 1,2,3,4};

    //! f(x) = x
    auto func1 = [](int i){  return i; };
    FuncWrapper wrapper(v.cbegin(), v.cend(), v.cbegin(), v.cend(), func1);
    dma::println(wrapper.is_onto()? "onto!" : "not onto.");

    //! f(x) = x * x
    auto func2 = [](int i){  return i * i; };
    wrapper.reset(func2);
    dma::println(wrapper.is_onto()? "onto !" : "not onto.");

    dma::exit();
    return 0;
}
//! @output
//!
//dma> onto!
//dma> not onto.
//dma> exit normally
