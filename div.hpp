#ifndef DIV_H
#define DIV_H

#include "base.hpp"

class Div : public Base
{
    public:
        Base* left;
        Base* right;
        Div(Base* l,Base* r){
                this->left = l;
                this->right = r;
        };
        double evaluate(){
            return this->left->evaluate() / this->right->evaluate();
        };
        std::string stringify(){
            return "(" + this->left->stringify() + "/" + this->right->stringify() + ")";
        };
        void accept(Visitor* v,int index){
            if (index == 0){
                v->visit_div_begin(this);
            }
            else if(index == 1){
                v->visit_div_middle(this);
            }
            else if(index == 2){
                v->visit_div_end(this);
            }
        };
};

#endif