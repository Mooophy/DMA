//!
//! @author Yue Wang
//! @date   22.11.2014
//!
//! @brief  implementationn for project 1, chapter 1.
//!

#include <iostream>
#include <vector>
#include "../include/utilities.hpp"

namespace dma{

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


//!
//! proj 1.
//! Given the truth values of the propositions p and q, find the
//! truth values of the conjunction, disjunction, exclusive or,
//! conditional statement, and biconditional of these proposi-
//! tions.
//!
void perform_proj01()
{
    dma::Find find;

    dma::print("conjunction : ");
    dma::print(find.conjunction(true,    true))  << " ";
    dma::print(find.conjunction(true,    false)) << " ";
    dma::print(find.conjunction(false,   true))  << " ";
    dma::print(find.conjunction(false,   false)) << "\n\n";

    dma::print("disjunction : ");
    dma::print(find.disjunction(true,    true))  << " ";
    dma::print(find.disjunction(true,    false)) << " ";
    dma::print(find.disjunction(false,   true))  << " ";
    dma::print(find.disjunction(false,   false)) << "\n\n";

    dma::print("exclusive or: ");
    dma::print(find.exclusive_or(true,    true))  << " ";
    dma::print(find.exclusive_or(true,    false)) << " ";
    dma::print(find.exclusive_or(false,   true))  << " ";
    dma::print(find.exclusive_or(false,   false)) << "\n\n";

    dma::print("bicondition : ");
    dma::print(find.bicondition(true,    true))  << " ";
    dma::print(find.bicondition(true,    false)) << " ";
    dma::print(find.bicondition(false,   true))  << " ";
    dma::print(find.bicondition(false,   false)) << "\n\n";

    dma::print("condition statement: ");
    dma::print(find.condition_statement(true,    true))  << " ";
    dma::print(find.condition_statement(true,    false)) << " ";
    dma::print(find.condition_statement(false,   true))  << " ";
    dma::print(find.condition_statement(false,   false)) << "\n\n";
}
}//namespace

int main()
{
    dma::perform_proj01();
    dma::exit();
    return 0;
}
//! output
//!
//conjunction : 1 0 0 0

//disjunction : 1 1 1 0

//exclusive or: 0 1 1 0

//bicondition : 1 0 0 1

//condition statement: 1 0 1 1


//exit normally
