#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
	public:
		double val;
		int number_of_children() {return 0;}
        Base* get_child(int i) {return nullptr;}
		Rand() : Base() { val = rand() % 100; }
		virtual double evaluate() { return val; };
		virtual std::string stringify() { 
			std::string stringVal = std::to_string(val);
			return stringVal;
		}
		virtual void accept(Visitor* v,int index){
            v->visit_rand(this);
        };
};

#endif //__RAND_HPP__		
