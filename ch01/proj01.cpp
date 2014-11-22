//!
//! @author Yue Wang
//! @date   22.11.2014
//!
//! @brief  implementationn for project 1, chapter 1.
//!

#include <iostream>
#include <vector>
#include "../include/dm.hpp"

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


//!
//! proj 1.
//! Given the truth values of the propositions p and q, find the
//! truth values of the conjunction, disjunction, exclusive or,
//! conditional statement, and biconditional of these proposi-
//! tions.
//!
void perform_proj01()
{
    dm::Find find;

    dm::print("conjunction : ");
    dm::print(find.conjunction(true,    true))  << " ";
    dm::print(find.conjunction(true,    false)) << " ";
    dm::print(find.conjunction(false,   true))  << " ";
    dm::print(find.conjunction(false,   false)) << "\n\n";

    dm::print("disjunction : ");
    dm::print(find.disjunction(true,    true))  << " ";
    dm::print(find.disjunction(true,    false)) << " ";
    dm::print(find.disjunction(false,   true))  << " ";
    dm::print(find.disjunction(false,   false)) << "\n\n";

    dm::print("exclusive or: ");
    dm::print(find.exclusive_or(true,    true))  << " ";
    dm::print(find.exclusive_or(true,    false)) << " ";
    dm::print(find.exclusive_or(false,   true))  << " ";
    dm::print(find.exclusive_or(false,   false)) << "\n\n";

    dm::print("bicondition : ");
    dm::print(find.bicondition(true,    true))  << " ";
    dm::print(find.bicondition(true,    false)) << " ";
    dm::print(find.bicondition(false,   true))  << " ";
    dm::print(find.bicondition(false,   false)) << "\n\n";

    dm::print("condition statement: ");
    dm::print(find.condition_statement(true,    true))  << " ";
    dm::print(find.condition_statement(true,    false)) << " ";
    dm::print(find.condition_statement(false,   true))  << " ";
    dm::print(find.condition_statement(false,   false)) << "\n\n";
}
}//namespace

int main()
{
    dm::perform_proj01();
    dm::exit();

    return 0;
}

