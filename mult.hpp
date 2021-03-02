#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

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
};

#endif //__MULT_HPP__
