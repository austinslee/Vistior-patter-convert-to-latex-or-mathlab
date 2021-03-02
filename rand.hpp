#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "visitor.hpp"

using namespace std;

class Rand : public Base {
	public:
		double val;
		Rand() : Base() { val = rand() % 100; }
		virtual double evaluate() { return val; };
		virtual string stringify() { 
			string stringVal = to_string(val);
			return stringVal;
		}
		void accept(Visitor*);
};

void Rand::accept(Visitor* v)
{
	v->visit_rand(this);
}

#endif //__RAND_HPP__		