#include <iostream>
#include "../include/utilities.hpp"
#include "search.hpp"
#include <vector>

int main()
{
    std::vector<int> v{5,6,7,8,9,12345};
    dma::println(*dma::binary_search(v.cbegin(),v.cend(),12345));

    return 0;
}

