#include "visitor.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"

class LaTeXVisitor : public Visitor
{
public:
std::string syntax = "";
virtual void visit_rand(Rand* node)
{
    syntax += ("{" + node->stringify() + "}");
}

void visit_op(Op* node)
{
    syntax += "{" + node->stringify() + "}";
}

void visit_add_begin(Add* node)
{
    syntax += "{({";
}

void visit_add_middle(Add* node)
{
    syntax += "}+{";
}

void visit_add_end(Add* node)
{
    syntax += "})}";
}

void visit_sub_begin(Sub* node)
{
    syntax += "{({";
}

void visit_sub_middle(Sub* node)
{
    syntax += "}-{";
}

void visit_sub_end(Sub* node)
{
    syntax += "})}";
}

void visit_mult_begin(Mult* node)
{
    syntax += "{({";
}

void visit_mult_middle(Mult* node)
{
    syntax += "}\\cdot{";
}

void visit_mult_end(Mult* node)
{
    syntax += "})}";
}

void visit_div_begin(Div* node)
{
    syntax += "{\\frac{";
}

void visit_div_middle(Div* node)
{
    syntax += "}{";
}

void visit_div_end(Div* node)
{
    syntax += "}}";
}

void visit_pow_begin(Pow* node)
{
    syntax += "{({";
}

void visit_pow_middle(Pow* node)
{
    syntax += "}^{";
}

void visit_pow_end(Pow* node)
{
    syntax += "})}";
}

std::string PrintLaTeX()
{
    return ("$" + syntax + "$");
}

};
