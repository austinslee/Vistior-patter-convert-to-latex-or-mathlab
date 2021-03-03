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
    std::string out = "";
    std::cout << lv->PrintLaTeX() << std::endl;
    out = lv->PrintLaTeX();
    delete lv;
    return out;
    
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
    std::string out;
    std::cout<<mlv->end()<<std::endl;
    out = mlv->end();
    delete mlv;
    return out;
}

int main()
{
    Base* five = new Op(5);
	Base* one = new Op(1);
	Base* zero = new Op(0);
	Base* sub1 = new Sub(five,zero);
	Base* add1 = new Add(one,sub1);

    std::cout << add1->stringify() << " = " << add1->evaluate() << std::endl;
    Print(add1);
	PrintML(add1);

    delete (five,one,zero,sub1,add1);
}
