#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
	    double val;
        int number_of_children() {return 0;}
        Base* get_child(int i) {return nullptr;}
        Op(double value) : Base() { this->val = value; }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { 
		std::string stringVal = std::to_string(val);
		return stringVal;
	}
        void accept(Visitor* v, int index){
            v->visit_op(this);
        }
};

#endif //__OP_HPP__
