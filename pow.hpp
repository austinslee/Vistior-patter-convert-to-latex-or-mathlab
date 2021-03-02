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
};
			
#endif //__POW_HPP__
