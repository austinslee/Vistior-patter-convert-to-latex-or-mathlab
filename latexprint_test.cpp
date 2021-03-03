#include <string.h>
#include <iostream>
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

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

    Iterator i(sub1);
    LaTeXVisitor* lv = new LaTeXVisitor;
    while(!i.is_done())
    {
        i.current_node()->accept(lv,i.current_index());
        i.next();
    }
    lv->PrintLaTeX(sub1);
}