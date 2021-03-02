#ifndef __POW_HPP__
#define __POW_HPP__

#include<cmath>

#include "base.hpp"

using namespace std;

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
		
		virtual string stringify() {
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
        };
};
			
#endif //__POW_HPP__
