#ifndef __MATHMLVISITOR_HPP__
#define __MATHMLVISITOR_HPP__

#include "visitor.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"

class MathMLVisitor : public Visitor
{
    public:
    std::string syntax = "<math>\n\t<apply>\n";
    int indent = 2;
    
    void visit_op(Op* node){
    for (int i = 0; i < indent; i++){ syntax += "\t"; }
    syntax += "<cn>";
    syntax += node->stringify();
    syntax += "</cn>\n";
    }


    void visit_rand(Rand* node){
    for (int i = 0; i < indent; i++){ syntax += "\t";}
    syntax += "<cn>";
    syntax += node->stringify();
    syntax += "</cn>\n";
    }  

    void visit_add_begin(Add* node){
    for (int i = 0; i < indent; i++){ syntax += "\t";}
    syntax += "<plus/>\n";
    if( node->get_child(0)->number_of_children() != 0) {
        for (int i = 0; i < indent; i++) { syntax += "\t"; }
        syntax += "<apply>\n";
        indent++;
        }
    }

    void visit_add_middle(Add* node){
    if(node->get_child(0)->number_of_children() != 0){
        indent--;
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "</apply>\n";
    }
    if(node->get_child(1)->number_of_children() != 0){
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "<apply>\n";
        indent++;
        }
    }
    void visit_add_end(Add* node){
    if(node->get_child(1)->number_of_children() != 0){
        indent--;
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "</apply>\n";
        }
    }   
    void visit_sub_begin(Sub* node){
    for (int i = 0; i < indent; i++){ syntax += "\t";}
    syntax += "<minus/>\n";
    if( node->get_child(0)->number_of_children() != 0) {
        for (int i = 0; i < indent; i++) { syntax += "\t"; }
        syntax += "<apply>\n";
        indent++;
        }
    }
    void visit_sub_middle(Sub* node){
    if(node->get_child(0)->number_of_children() != 0){
        indent--;
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "</apply>\n";
        }
    if(node->get_child(1)->number_of_children() != 0){
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "<apply>\n";
        indent++;
        }
    }
    void visit_sub_end(Sub* node){
        if(node->get_child(1)->number_of_children() != 0){
            indent--;
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "</apply>\n";
        }
    }
    void visit_mult_begin(Mult* node){
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "<times/>\n";
        if( node->get_child(0)->number_of_children() != 0) {
            for (int i = 0; i < indent; i++) { syntax += "\t"; }
            syntax += "<apply>\n";
            indent++;
        }
    }
    void visit_mult_middle(Mult* node){
        if(node->get_child(0)->number_of_children() != 0){
            indent--;
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "</apply>\n";
        }
        if(node->get_child(1)->number_of_children() != 0){
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "<apply>\n";
            indent++;
        }
    }
    void visit_mult_end(Mult* node){
        if(node->get_child(1)->number_of_children() != 0){
            indent--;
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "</apply>\n";
        }
    }
    void visit_div_begin(Div* node){
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "<divide/>\n";
        if( node->get_child(0)->number_of_children() != 0) {
            for (int i = 0; i < indent; i++) { syntax += "\t"; }
            syntax += "<apply>\n";
            indent++;
        }
    }
    void visit_div_middle(Div* node){
        if(node->get_child(0)->number_of_children() != 0){
            indent--;
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "</apply>\n";
        }
        if(node->get_child(1)->number_of_children() != 0){
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "<apply>\n";
            indent++;
        }
    }
    void visit_div_end(Div* node){
        if(node->get_child(1)->number_of_children() != 0){
            indent--;
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "</apply>\n";
        }
    }
    void visit_pow_begin(Pow* node){
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        syntax += "<power/>\n";
        if( node->get_child(0)->number_of_children() != 0) {
            for (int i = 0; i < indent; i++) { syntax += "\t"; }
            syntax += "<apply>\n";
            indent++;
        }
    }
    void visit_pow_middle(Pow* node){
        if(node->get_child(0)->number_of_children() != 0){
            indent--;
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "</apply>\n";
        }
        if(node->get_child(1)->number_of_children() != 0){
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "<apply>\n";
            indent++;
        }
    }
    void visit_pow_end(Pow* node){
        if(node->get_child(1)->number_of_children() != 0){
            indent--;
            for (int i = 0; i < indent; i++){ syntax += "\t";}
            syntax += "</apply>\n";
        }
    }

    std::string ented() {
        indent = 1;
        for (int i = 0; i < indent; i++){ syntax += "\t";}
        indent = 0;
        syntax += "</apply>\n";
        syntax += "</math>\n";
        return syntax;
    }
};

#endif
