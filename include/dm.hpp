#ifndef DM_HPP
#define DM_HPP

#include <iostream>

namespace dma
{
using Proposition       =   bool;
using FuzzyProposition  =   double;

template<typename Printable>
std::ostream& println(Printable const& to_print)
{
    return std::cout << to_print << std::endl;
}

template<typename Printable>
std::ostream& println(Printable && to_print)
{
    return std::cout << to_print << std::endl;
}

template<typename Printable>
std::ostream& print(Printable const& to_print)
{
    return std::cout << to_print ;
}

template<typename Printable>
std::ostream& print(Printable && to_print)
{
    return std::cout << std::move(to_print);
}

void exit()
{
    std::cout << "\nexit normally" << std::endl;
}
}//namespace 

#endif
