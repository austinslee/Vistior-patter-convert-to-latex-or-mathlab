#ifndef SUB_H
#define SUB_H

#include "base.hpp"

class Sub : public Base
{
    public:
        Base* left;
        Base* right;
        Sub(Base* l,Base* r){
                this->left = l;
                this->right = r;
        };
        double evaluate(){
            return this->left->evaluate() - this->right->evaluate();
        };
        std::string stringify(){
            return "(" + this->left->stringify() + "-" + this->right->stringify() + ")";
        };
        void accept(Visitor* v,int index){
            if (index == 0){
                v->visit_sub_begin(this);
            }
            else if(index == 1){
                v->visit_sub_middle(this);
            }
            else if(index == 2){
                v->visit_sub_end(this);
            }
        };

};

#endif