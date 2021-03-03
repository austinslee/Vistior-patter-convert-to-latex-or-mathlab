#include <string.h>
#include <iostream>
#include "latexvisitor.hpp"
#include "iterator.hpp"
#include "mathmlvisitor.hpp"

std::string Print(Base* ptr)
{
    Iterator i(ptr);
    LaTeXVisitor* lv = new LaTeXVisitor;
    while(!i.is_done())
    {
        i.current_node()->accept(lv,i.current_index());
        i.next();
    }
    std::cout << lv->PrintLaTeX() << std::endl;
    
}

std::string PrintML(Base* ptr)
{
    Iterator i(ptr);
    MathMLVisitor* mlv = new MathMLVisitor;
    while(!i.is_done())
    {
        i.current_node()->accept(mlv,i.current_index());
        i.next();
    }
    std::cout<<mlv->ented()<<std::endl;
}

int main()
{
    Base* six = new Op(6);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* five = new Op(5);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(six, mult);
    Base* minus = new Sub(add, five);
    Base* div = new Div(minus, five);
    Base* pow = new Pow(div, five);

	Base* one = new Op(1);
	Base* zero = new Op(0);
	Base* sub1 = new Sub(five,zero);
	Base* add1 = new Add(one,sub1);

    std::cout << add1->stringify() << " = " << add1->evaluate() << std::endl;
    Print(pow);
	PrintML(add1);
}
