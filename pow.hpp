#ifndef __POW_HPP__
#define __POW_HPP__

#include<cmath>

#include "base.hpp"
#include "visitor.hpp"

class Pow : public Base {
	public:
		Base* operand;
		Base* exponent;

		Pow(Base* input1, Base* input2) : Base() {
			operand = input1;
			exponent = input2;
		}

		virtual double evaluate() {			
			return pow(operand->evaluate(), exponent->evaluate());
		}
		
		virtual std::string stringify() {
			return "(" + operand->stringify() + "**" + exponent->stringify() + ")";
		}

		void accept(Visitor* v,int index){
            if (index == 0){
                v->visit_pow_begin(this);
            }
            else if(index == 1){
                v->visit_pow_middle(this);
            }
            else if(index == 2){
                v->visit_pow_end(this);
            }
        }

        int number_of_children() {return 2;}

        Base* get_child(int i) {
                if(i == 0) { return this->operand; }
                if(i == 1) { return this->exponent; }
                return nullptr;
        }
	

};
			
#endif //__POW_HPP__
