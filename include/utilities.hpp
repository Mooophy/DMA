#ifndef UTILITTIES_HPP
#define UTILITTIES_HPP

#include <iostream>

namespace dma
{
using Proposition       =   bool;
using FuzzyProposition  =   double;

template<typename Printable>
std::ostream& println(Printable const& to_print)
{
    return std::cout << "dma> " << to_print << std::endl;
}

template<typename Printable>
std::ostream& println(Printable && to_print)
{
    return std::cout << "dma> " << to_print << std::endl;
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

template<typename Range>
inline std::ostream& println_range(Range const& rng)
{
    std::cout << "dma> ";
    for(auto elem : rng)    std::cout << elem << " ";
    return std::cout << std::endl;
}

void exit()
{
    dma::println("exit normally");
}
}//namespace 

#endif
