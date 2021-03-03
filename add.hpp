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

	int number_of_children() { 
		int num = 0;
		if(left != nullptr) { ++num; }
		if(right != nullptr) { ++num; }
		return num;
	}
	
	Base* get_child(int i) {
		if(i == 1) { return left; }
		if(i == 2) { return right; }
		return nullptr;
	}

};

#endif
