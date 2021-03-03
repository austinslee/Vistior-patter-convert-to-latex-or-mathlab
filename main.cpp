#include <string.h>
#include <iostream>
#include "latexvisitor.hpp"
#include "iterator.hpp"

std::string Print(Base* ptr)
{
    Iterator i(ptr);
    LaTeXVisitor* lv = new LaTeXVisitor;
    while(!i.is_done())
    {
        i.current_node()->accept(lv,i.current_index());
        i.next();
    }
    lv->PrintLaTeX();
}

int main()
{
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    Base* add1 = new Add(three, four);
    Base* sub1 = new Sub(add1, two);

    std::cout << Print(sub1) << std::endl;
    return 0;
}