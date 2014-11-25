#include <vector>
#include <functional>
#include "function.hpp"
#include "../include/utilities.hpp"

int main()
{
    using Iter          =   typename    std::vector<int>::const_iterator;
    using FuncWrapper   =               dma::Function<Iter, std::function<int(int)> >;

    auto func = [](int i){  return i; };
    std::vector<int> v{1,2,3,4};
    FuncWrapper wrapper(v.cbegin(), v.cend(), v.cbegin(), v.cend(),func);

    dma::println(wrapper.is_one2one());
}
