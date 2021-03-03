#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "visitor.hpp"

using namespace std;

class Mult : public Base {
	public:
		Base* operand1;
		Base* operand2;
		Mult(Base* left, Base* right) : Base() { 
			operand1 = left;
			operand2 = right;
		}
		virtual double evaluate() {
			return this->operand1->evaluate() * this->operand2->evaluate();
		}
		virtual string stringify() {

			return "(" + this->operand1->stringify() + "*" + this->operand2->stringify() + ")";
		}
		void accept(Visitor* v,int index){
            if (index == 0){
                v->visit_mult_begin(this);
            }
            else if(index == 1){
                v->visit_mult_middle(this);
            }
            else if(index == 2){
                v->visit_mult_end(this);
            }
        };

        int number_of_children() {
                int num = 0;
                if(operand1 != nullptr) { ++num; }
                if(operand2 != nullptr) { ++num; }
                return num;
        }

        Base* get_child(int i) {
                if(i == 1) { return operand1; }
                if(i == 2) { return operand2; }
                return nullptr;
        }

};

#endif //__MULT_HPP__
