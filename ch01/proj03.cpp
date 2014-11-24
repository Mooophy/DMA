//!
//! @author Yue wang
//! @date   24.11.2014
//!
//! proj 3
//! Given the truth values of the propositions p and q in
//! fuzzy logic, find the truth value of the disjunction and
//! the conjunction of p and q.
//!
#include "../include/dm.hpp"
#include <algorithm>

namespace dm {

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
    dm::Fuzzy fz;
    dm::FuzzyProposition p = 0.4, q = 0.8;
    auto conj = fz.find_conjunction(p,q);
    auto disj = fz.find_disjunction(p,q);

    dm::println(conj);
    dm::println(disj);

    dm::exit();
    return 0;
}
//! output
//!
//0.4
//0.8

//exit normally
