#include <iostream>
#include "../include/utilities.hpp"
#include "search.hpp"
#include "sort.hpp"
#include <vector>

int main()
{
    std::vector<int> v{5,6,3,7,2,8,1,9,12345};
    dma::println_range(v);
    dma::bubble_sort(v.begin(),v.end());
    dma::println_range(v);

    return 0;
}

