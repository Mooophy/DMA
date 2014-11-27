#include <iostream>
#include "../include/utilities.hpp"
#include "search.hpp"
#include "sort.hpp"
#include <vector>

int main()
{
    std::vector<int> v{5,2,6,3,4,7,1};
    dma::println_range(v);
    dma::insertion_sort(v.begin(),v.end());
    dma::println_range(v);

    return 0;
}

