//!
//! @author Yue wang
//! @date   24.11.2014
//!
//! proj 3
//! Given the truth values of the propositions p and q in
//! fuzzy logic, find the truth value of the disjunction and
//! the conjunction of p and q.
//!
#include "../include/utilities.hpp"
#include <algorithm>

namespace dma {

/**
 * @brief functor to find disjunction and conjunction for fuzzy propositions.
 */
struct Fuzzy
{
    using TruethValue = double;

    TruethValue find_disjunction(FuzzyProposition p, FuzzyProposition q)
    {
        return std::max(p,q);
    }

    TruethValue find_conjunction(FuzzyProposition p, FuzzyProposition q)
    {
        return std::min(p,q);
    }
};
}//namespace

int main()
{
    dma::Fuzzy fz;
    dma::FuzzyProposition p = 0.4, q = 0.8;
    auto conj = fz.find_conjunction(p,q);
    auto disj = fz.find_disjunction(p,q);

    dma::println(conj);
    dma::println(disj);

    dma::exit();
    return 0;
}
//! output
//!
//0.4
//0.8

//exit normally
