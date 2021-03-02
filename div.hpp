#ifndef DIV_H
#define DIV_H

#include "base.hpp"

class Div : public Base
{
    public:
        Div(Base*,Base*);
        double evaluate();
        std::string stringify();
        Base* left;
        Base* right;
};

Div::Div(Base* l, Base*r)
{
    this->left = l;
    this->right = r;
};

double Div::evaluate()
{
    return this->left->evaluate() / this->right->evaluate();
};

std::string Div::stringify()
{
    return "(" + this->left->stringify() + "/" + this->right->stringify() + ")";
};


#endif