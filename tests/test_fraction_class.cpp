#include "fraction.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(FractionTest, PositiveNums){
    Fraction f(1, 2);

    EXPECT_EQ(f.numerator, 1);
    EXPECT_EQ(f.denominator, 2);
}

TEST(FractionTest, NegativeNums){
    Fraction f1(-3, 4);

    EXPECT_EQ(f1.numerator, -3);
    EXPECT_EQ(f1.denominator, 4);

    Fraction f2(2, -5);

    EXPECT_EQ(f2.numerator, 2);
    EXPECT_EQ(f2.denominator, -5);

    Fraction f3(-6, -7);

    EXPECT_EQ(f3.numerator, -6);
    EXPECT_EQ(f3.denominator, -7);
}

TEST(FractionTest, SimplifyFunction){
    Fraction f1(3, 6);
    f1.simplify();

    EXPECT_EQ(f1.numerator, 1);
    EXPECT_EQ(f1.denominator, 2);

    Fraction f2(-2, 8);
    f2.simplify();

    EXPECT_EQ(f2.numerator, -1);
    EXPECT_EQ(f2.denominator, 4);

    Fraction f3(6, -3);
    f3.simplify();

    EXPECT_EQ(f3.numerator, 2);
    EXPECT_EQ(f3.denominator, -1);

    Fraction f4(-8, -6);
    f4.simplify();

    EXPECT_EQ(f4.numerator, 4);
    EXPECT_EQ(f4.denominator, 3);
}

TEST(FractionTest, NonZeroDenominatorCheck){
    ASSERT_THROW(Fraction f(1, 0), std::invalid_argument);
}

TEST(FractionOperators, TestStreamInsertionOperator){
    std::stringstream ss;
    Fraction f1(2, 3);

    ss << f1;
    EXPECT_EQ(ss.str(), "2/3");

    ss.str(""); //clears string stream buffer

    Fraction f2(1, 6);

    ss << f2;
    EXPECT_EQ(ss.str(), "1/6");
}

TEST(FractionOperators, TestAdditionAssignmentOperator){
    Fraction f(1, 4);
    f += Fraction(1, 4);
    EXPECT_EQ(f, Fraction(1, 2));

    f += Fraction(1, 4);
    EXPECT_EQ(f, Fraction(3, 4));

    f += Fraction(1, 5);
    EXPECT_EQ(f, Fraction(19, 20));
}

TEST (FractionOperators, TestBinaryAdditionOperator){
    Fraction f1(1, 5);
    Fraction f2(2, 5);
    Fraction sum1 = f1 + f2;
    EXPECT_EQ(sum1, Fraction(3, 5));

    Fraction f3(1, 2);
    Fraction f4(1, 5);
    Fraction sum2 = f3 + f4;
    EXPECT_EQ(sum2, Fraction(7, 10));

    Fraction f5(1, 3);
    Fraction f6(4, 9);
    Fraction sum3 = f5 + f6;
    EXPECT_EQ(sum3, Fraction(7, 9));

    Fraction f7(4, 11);
    Fraction f8(6, 17);
    Fraction sum4 = f7 + f8;
    EXPECT_EQ(sum4, Fraction(134, 187));
}

TEST (FractionOperators, TestSubtractionAssignmentOperator){
    Fraction f(5, 8);
    f -= Fraction(1, 4);
    EXPECT_EQ(f, Fraction(3, 8));

    f -= Fraction(3, 16);
    EXPECT_EQ(f, Fraction(3, 16));

    f -= Fraction(5, 26);
    EXPECT_EQ(f, Fraction(-1, 208));
}