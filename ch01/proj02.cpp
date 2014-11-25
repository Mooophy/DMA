//!
//! @author Yue Wang
//! @date   22.11.2014
//!
//! proj 2.
//! Given two bit strings of length n, find the bitwise AND,
//! bitwise OR, and bitwise XOR of these strings
//!

#include"bit_string.hpp"

int main()
{
    dm::BitString lhs("1010"), rhs("1111");

    auto res_of_and =   lhs & rhs;
    auto res_of_or  =   lhs | rhs;
    auto res_of_xor =   lhs ^ rhs;

    dm::println(res_of_and);
    dm::println(res_of_or);
    dm::println(res_of_xor);

    dm::exit();
    return 0;
}
//! output
//!
//1010
//1111
//0101

//exit normally
