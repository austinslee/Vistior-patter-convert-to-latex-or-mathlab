#ifndef ADD_H
#define ADD_H

#include "base.hpp"
#include "visitor.hpp"

class Add : public Base
{
    public:
        Add(Base*, Base*);
        double evaluate();
        std::string stringify();
        Base* left;
        Base* right;
        void accept(Visitor*);
        
};

Add::Add(Base* l, Base* r)
{
    this->left=l;
    this->right=r;
};

double Add::evaluate()
{
    return this->left->evaluate() + this->right->evaluate();
};

std::string Add::stringify()
{
    return "(" + this->left->stringify() + "+" + this->right->stringify() + ")";
};

void Add::accept(Visitor* v)
{
    
}

#endif