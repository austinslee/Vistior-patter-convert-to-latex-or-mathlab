#include "visitor.hpp"
#include "iterator.hpp"

LaTeXVisitor::LaTeXVisitor() : Visitor()
{
    
};

void LaTeXVisitor::visit_rand(Rand* node)
{
    output += "{" + node->stringify() + "}";
};

void LaTeXVisitor::visit_op(Op* node)
{
    output += "{" + node->stringify() + "}";
};

void LaTeXVisitor::visit_add_begin(Add* node)
{
    output += "{({";
};

void LaTeXVisitor::visit_add_middle(Add* node)
{
    output += "}+{";
};

void LaTeXVisitor::visit_add_end(Add* node)
{
    output += "})}";
};

void LaTeXVisitor::visit_sub_begin(Sub* node)
{
    output += "{({";
};

void LaTeXVisitor::visit_sub_middle(Sub* node)
{
    output += "}-{";
};

void LaTeXVisitor::visit_sub_end(Sub* node)
{
    output += "})}";
};

void LaTeXVisitor::visit_mult_begin(Mult* node)
{
    output += "{({";
};

void LaTeXVisitor::visit_mult_middle(Mult* node)
{
    output += "}\\cdot{";
};

void LaTeXVisitor::visit_mult_end(Mult* node)
{
    output += "})}";
};

void LaTeXVisitor::visit_div_begin(Div* node)
{
    output += "{\\frac{";
};

void LaTeXVisitor::visit_div_middle(Div* node)
{
    output += "}{";
};

void LaTeXVisitor::visit_div_end(Div* node)
{
    output += "}}";
};

void LaTeXVisitor::visit_pow_begin(Pow* node)
{
    output += "{({";
};

void LaTeXVisitor::visit_pow_middle(Pow* node)
{
    output += "}^{";
};

void LaTeXVisitor::visit_pow_end(Pow* node)
{
    output += "})}";
};

std::string LaTeXVisitor::PrintLaTeX(Base* ptr)
{
    return ("$" + output + "$");
};
