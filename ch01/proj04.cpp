//!
//! @author Yue Wang
//! @date   24.11.2014
//!
//! proj 4 for ch1 DMA
//!

#include "../include/utilities.hpp"
#include "bit_string.hpp"

int main()
{
    dma::BitString A("0111"), B("1001");
    dma::println(!A);    //complement
    dma::println(A | B); //union
    dma::println(A & B); //intersection
    dma::println(A ^ B); //xor
    dma::println(A - B); //difference

    dma::exit();
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
