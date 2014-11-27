#include <iostream>
#include "../include/utilities.hpp"
#include "search.hpp"
#include <vector>

int main()
{
    std::vector<int> v{1,22,3,4,5,6,7,8};
    dma::println(*dma::linear_search(v.cbegin(),v.cend(),22));

    return 0;
}

