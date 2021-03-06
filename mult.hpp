#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
	public:
		Base* operand1 = nullptr;
		Base* operand2 = nullptr;
		Mult(Base* left, Base* right) : Base() { 
			operand1 = left;
			operand2 = right;
		}

		Mult() {}

		Mult(Base* l) { operand1 = l; }		

		~Mult() {
			delete operand1;
			delete operand2;
		}

		virtual double evaluate() {
			return this->operand1->evaluate() * this->operand2->evaluate();
		}
		virtual std::string stringify() {

			return "(" + this->operand1->stringify() + "*" + this->operand2->stringify() + ")";
		}
		virtual void accept(Visitor* v,int index){
            if (index == 0){
                v->visit_mult_begin(this);
            }
            else if(index == 1){
                v->visit_mult_middle(this);
            }
            else if(index == 2){
                v->visit_mult_end(this);
            }
        }

        virtual int number_of_children() {
		int x = 0;
		if(operand1 != nullptr) { ++x; }
		if(operand2 != nullptr) { ++x; }
		return x;
	}

        virtual Base* get_child(int i) {
                if(i == 0) { return operand1; }
                if(i == 1) { return operand2; }
                return nullptr;
        }

};

#endif //__MULT_HPP__
