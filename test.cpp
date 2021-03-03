#include "gtest/gtest.h"

#include "latexvisitor.hpp"
#include "iterator.cpp"
#include "mathmlvisitor.hpp"
#include <string.h>
#include <iostream>

std::string Print(Base* ptr)
{
	std::string total = "";
    Iterator i(ptr);
    LaTeXVisitor* lv = new LaTeXVisitor;
    while(!i.is_done())
    {
        i.current_node()->accept(lv,i.current_index());
        i.next();
    }
    total += lv->PrintLaTeX() + "\n";

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



TEST(ChildTest, NumberOfChildren0ChildAdd) {
	Base* test = new Add();
	EXPECT_EQ(test->number_of_children(), 0);	
}

TEST(ChildTest, NumberOfChildren1ChildAdd) {
        Base* test = new Add(new Op(3));
        EXPECT_EQ(test->number_of_children(), 1);
}

TEST(ChildTest, NumberOfChildren2ChildAdd) {
        Base* test = new Add(new Op(3), new Op(3));
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(ChildTest, NumberOfChildren0ChildSub) {
        Base* test = new Sub();
        EXPECT_EQ(test->number_of_children(), 0);
}

TEST(ChildTest, NumberOfChildren1ChildSub) {
        Base* test = new Sub(new Op(3));
        EXPECT_EQ(test->number_of_children(), 1);
}

TEST(ChildTest, NumberOfChildren2ChildSub) {
        Base* test = new Sub(new Op(3), new Op(3));
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(ChildTest, NumberOfChildren0ChildMult) {
        Base* test = new Mult();
        EXPECT_EQ(test->number_of_children(), 0);
}

TEST(ChildTest, NumberOfChildren1ChildMult) {
        Base* test = new Mult(new Op(3));
        EXPECT_EQ(test->number_of_children(), 1);
}

TEST(ChildTest, NumberOfChildren2ChildMult) {
        Base* test = new Mult(new Op(3), new Op(3));
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(ChildTest, NumberOfChildren0ChildDiv) {
        Base* test = new Div();
        EXPECT_EQ(test->number_of_children(), 0);
}

TEST(ChildTest, NumberOfChildren1ChildDiv) {
        Base* test = new Div(new Op(3));
        EXPECT_EQ(test->number_of_children(), 1);
}

TEST(ChildTest, NumberOfChildren2ChildDiv) {
        Base* test = new Div(new Op(3), new Op(3));
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(ChildTest, NumberOfChildren0ChildPow) {
        Base* test = new Pow();
        EXPECT_EQ(test->number_of_children(), 0);
}

TEST(ChildTest, NumberOfChildren1ChildPow) {
        Base* test = new Pow(new Op(3));
        EXPECT_EQ(test->number_of_children(), 1);
}

TEST(ChildTest, NumberOfChildren2ChildPow) {
        Base* test = new Div(new Op(3), new Op(3));
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(ChildTest, getChildAdd0) {
	Add* test = new Add(new Op(3), new Op(3));
	EXPECT_EQ(test->get_child(0),test->left);
}

TEST(ChildTest, getChildAdd1) {
        Add* test = new Add(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(1),test->right);
}

TEST(ChildTest, getChildSub0) {
        Sub* test = new Sub(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(0),test->left);
}

TEST(ChildTest, getChildSub1) {
        Sub* test = new Sub(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(1),test->right);
}


TEST(ChildTest, getChildMult0) {
        Mult* test = new Mult(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(0),test->operand1);
}

TEST(ChildTest, getChildMult1) {
        Mult* test = new Mult(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(1),test->operand2);
}

TEST(ChildTest, getChildDiv0) {
        Div* test = new Div(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(0),test->left);
}

TEST(ChildTest, getChildDiv1) {
        Div* test = new Div(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(1),test->right);
}

TEST(ChildTest, getChildPow0) {
        Pow* test = new Pow(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(0),test->operand);
}

TEST(ChildTest, getChildPow1) {
        Pow* test = new Pow(new Op(3), new Op(3));
        EXPECT_EQ(test->get_child(1),test->exponent);
}

TEST(LatexTest, test1) {
	std::string total;
	Base* test = new Add(new Op(1), new Sub(new Op(5), new Op(0)));
	total = Print(test);

	EXPECT_EQ(total, "${({1}+{({5}-{0})})}$");
}

/*TEST(LatexTest, test2) {
        Base* test = new Pow(new Op(5), new Op(2));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        Print(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "${({5}^{2})}$");
}

TEST(LatexTest, test3) {
        Base* test = new Mult(new Op(2), new Op(5));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        Print(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "${({2}\cdot{5})}$");
}

TEST(LatexTest, test4) {
        Base* test = new Div(new Op(2), new Op(3));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        Print(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "${\frac{2}{3}}$");
}

TEST(LatexTest, test5) {
        Base* test = new Div(new Mult(new Op(2), new Op(5)), new Pow(new Op(5), new Op(2)));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        Print(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "${\frac{({2}\cdot{5})}{({5}^{2})}}$");
}

TEST(MLTest, test1) {
        Base* test = new Add(new Op(1), new Sub(new Op(5), new Op(0)));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        PrintML(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "<math>\n\t<apply>\n\t\t<plus/>\n\t\t<cn>1</cn>\n\t\t<apply>\n\t\t\t<minus/>\n\t\t\t<cn>5</cn>\n\t\t\t<cn>0</cn>\n\t\t</apply>\n\t</apply>\n</math>");
}

TEST(MLTest, test2) {
        Base* test = new Pow(new Op(5), new Op(2));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        PrintML(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "<math>\n\t<apply>\n\t\t<power/>\n\t\t<cn>5</cn>\n\t\t<cn>2</cn>\n\t</apply>\n</math>");
}

TEST(MLTest, test3) {
        Base* test = new Mult(new Op(2), new Op(5));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        PrintML(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "<math>\n\t<apply>\n\t\t<times/>\n\t\t<cn>2</cn>\n\t\t<cn>5</cn>\n\t</apply>\n</math>");
}

TEST(MLTest, test4) {
        Base* test = new Div(new Op(2), new Op(3));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        PrintML(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "<math>\n\t<apply>\n\t\t<divide/>\n\t\t<cn>2</cn>\n\t\t<cn>3</cn>\n\t</apply>\n</math>");
}

TEST(MLTest, test5) {
        Base* test = new Div(new Mult(new Op(2), new Op(5)), new Pow(new Op(5), new Op(2)));
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        PrintML(test);
        std::string capturedStdout = buffer.str();
        EXPECT_EQ(capturedStdout, "<math>\n\t<apply>\n\t\t<divide/>\n\t\t<apply>\n\t\t\t<times/>\n\t\t\t<cn>2</cn>\n\t\t\t<cn>5</cn>\n\t\t</apply>\n\t\t<apply>\n\t\t\t<power/>\n\t\t\t<cn>5</cn>\n\t\t\t<cn>2</cn>\n\t\t</apply>\n\t</apply>\n</math>");
}
*/





int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
