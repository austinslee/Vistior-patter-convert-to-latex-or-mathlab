#include "visitor.hpp"
#include "iterator.hpp"
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
    private:
    std::string output;

public:

virtual void visit_rand(Rand* node)
{
    output.append("{" + node->stringify() + "}");
}

void visit_op(Op* node)
{
    output += "{" + node->stringify() + "}";
}

void visit_add_begin(Add* node)
{
    output += "{({";
}

void visit_add_middle(Add* node)
{
    output += "}+{";
}

void visit_add_end(Add* node)
{
    output += "})}";
}

void visit_sub_begin(Sub* node)
{
    output += "{({";
}

void visit_sub_middle(Sub* node)
{
    output += "}-{";
}

void visit_sub_end(Sub* node)
{
    output += "})}";
}

void visit_mult_begin(Mult* node)
{
    output += "{({";
}

void visit_mult_middle(Mult* node)
{
    output += "}\\cdot{";
}

void visit_mult_end(Mult* node)
{
    output += "})}";
}

void visit_div_begin(Div* node)
{
    output += "{\\frac{";
}

void visit_div_middle(Div* node)
{
    output += "}{";
}

void visit_div_end(Div* node)
{
    output += "}}";
}

void visit_pow_begin(Pow* node)
{
    output += "{({";
}

void visit_pow_middle(Pow* node)
{
    output += "}^{";
}

void visit_pow_end(Pow* node)
{
    output += "})}";
}

std::string PrintLaTeX()
{
    return ("$" + output + "$");
}

};