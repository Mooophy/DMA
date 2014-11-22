#include <iostream>
#include <vector>
#include "../include/dm.hpp"

//!
//! proj 1.
//! Given the truth values of the propositions p and q, find the
//! truth values of the conjunction, disjunction, exclusive or,
//! conditional statement, and biconditional of these proposi-
//! tions.
//!

namespace dm{

struct Find
{
    Proposition conjunction(Proposition p, Proposition q)const
    {
        return p && q;
    }

    Proposition disjunction(Proposition p, Proposition q)const
    {
        return p || q;
    }

    Proposition exclusive_or(Proposition p, Proposition q)const
    {
        return p ^ q;
    }

    Proposition condition_statement(Proposition p, Proposition q)const
    {
        return !p || q;
    }

    Proposition bicondition(Proposition p, Proposition q)const
    {
        return (p && q) || (!p && !q);
    }
};
}//namespace

int main()
{
    dm::Find find;

    dm::print("conjunction : ");
    dm::print(find.conjunction(true,    true))  << " ";
    dm::print(find.conjunction(true,    false)) << " ";
    dm::print(find.conjunction(false,   true))  << " ";
    dm::print(find.conjunction(false,   false)) << "\n";

    dm::print("disjunction : ");
    dm::print(find.disjunction(true,    true))  << " ";
    dm::print(find.disjunction(true,    false)) << " ";
    dm::print(find.disjunction(false,   true))  << " ";
    dm::print(find.disjunction(false,   false)) << "\n";


    return 0;
}

