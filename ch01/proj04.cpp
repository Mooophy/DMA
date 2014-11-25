//!
//! @author Yue Wang
//! @date   24.11.2014
//!
//! proj 4 for ch1 DMA
//!

#include "../include/dm.hpp"
#include "bit_string.hpp"

int main()
{
    dm::BitString A("0111"), B("1001");
    dm::println(!A);    //complement
    dm::println(A | B); //union
    dm::println(A & B); //intersection
    dm::println(A ^ B); //xor
    dm::println(A - B); //difference

    dm::exit();
    return 0;
}
//! @output
//!
//1000
//1111
//0001
//1110
//0110

//exit normally
