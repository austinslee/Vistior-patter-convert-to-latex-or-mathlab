#ifndef SUB_H
#define SUB_H

#include "base.hpp"

class Sub : public Base
{
    public:
        Sub(Base*,Base*);
        double evaluate();
        std::string stringify();
        Base* left;
        Base* right;
};

Sub::Sub(Base* l, Base*r)
{
    this->left = l;
    this->right = r;
};

double Sub::evaluate()
{
    return this->left->evaluate() - this->right->evaluate();
};

std::string Sub::stringify()
{
    return "(" + this->left->stringify() + "-" + this->right->stringify() + ")";
};


#endif