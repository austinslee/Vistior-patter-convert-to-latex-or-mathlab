#ifndef ADD_H
#define ADD_H

#include "base.hpp"
#include "visitor.hpp"

class Add : public Base
{
    public:
        Base* left;
        Base* right;
        Add(Base* l, Base* r){
                this->left=l;
                this->right=r;
        };
        double evaluate(){
            return this->left->evaluate() + this->right->evaluate();
        };
        std::string stringify(){
            return "(" + this->left->stringify() + "+" + this->right->stringify() + ")";
        };
        void accept(Visitor* v,int index){
            if (index == 0){
                v->visit_add_begin(this);
            }
            else if(index == 1){
                v->visit_add_middle(this);
            }
            else if(index == 2){
                v->visit_add_end(this);
            }
        };
};

#endif