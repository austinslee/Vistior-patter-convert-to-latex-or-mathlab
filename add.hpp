#ifndef ADD_H
#define ADD_H

#include "base.hpp"

class Add : public Base
{
    public:
        Base* left = nullptr;
        Base* right = nullptr;
        Add(Base* l, Base* r){
                this->left=l;
                this->right=r;
        };

	Add(){}

	~Add() {
		delete left;
		delete right;
	}

	Add(Base* l) {
		left = l;
	}	

        virtual double evaluate(){
            return this->left->evaluate() + this->right->evaluate();
        }
        virtual std::string stringify(){
            return "(" + this->left->stringify() + "+" + this->right->stringify() + ")";
        }
        virtual void accept(Visitor* v,int index){
            if (index == 0){
                v->visit_add_begin(this);
            }
            else if(index == 1){
                v->visit_add_middle(this);
            }
            else if(index == 2){
                v->visit_add_end(this);
            }
        }

	virtual int number_of_children() {
		int x = 0;
		if(left != nullptr) { ++x; }
		if(right != nullptr) { ++x; }
		return x;		
	}
	
	virtual Base* get_child(int i) {
		if(i == 0) { return left; }
		if(i == 1) { return right; }
		return nullptr;
	}

};

#endif
