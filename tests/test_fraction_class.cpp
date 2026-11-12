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
    EXPECT_EQ(f1 + f2, Fraction(3, 5));

    Fraction f3(1, 2);
    Fraction f4(1, 5);
    EXPECT_EQ(f3 + f4, Fraction(7, 10));

    Fraction f5(1, 3);
    Fraction f6(4, 9);
    EXPECT_EQ(f5 + f6, Fraction(7, 9));

    Fraction f7(4, 11);
    Fraction f8(6, 17);
    EXPECT_EQ(f7 + f8, Fraction(134, 187));
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

TEST (FractionOperators, TestBinarySubtractionOperator){
    Fraction f1(4, 5);
    Fraction f2(1, 5);
    EXPECT_EQ(f1 - f2, Fraction(3, 5));

    Fraction f3(2, 3);
    Fraction f4(5, 12);
    EXPECT_EQ (f3 - f4, Fraction(1, 4));

    Fraction f5(5, 8);
    Fraction f6(1, 2);
    EXPECT_EQ(f5 - f6, Fraction(1, 8));

    Fraction f7(5, 7);
    Fraction f8(3, 11);
    EXPECT_EQ(f7 - f8, Fraction(34, 77));
}

TEST (FractionOperators, TestMultiplicationAssignmentOperator){
    Fraction f(1, 2);

    f *= Fraction(2, 3);
    EXPECT_EQ(f, Fraction(1, 3));

    f *= Fraction(7, 8);
    EXPECT_EQ(f, Fraction(7, 24));

    f *= Fraction(11, 13);
    EXPECT_EQ(f, Fraction(77, 312));
}

TEST (FractionOperators, TestBinaryMultiplicationOperator){
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    EXPECT_EQ(f1 * f2, Fraction(1, 6));

    Fraction f3(2, 5);
    Fraction f4(5, 6);
    EXPECT_EQ(f3 * f4, Fraction(1, 3));

    Fraction f5(3, 11);
    Fraction f6(7, 20);
    EXPECT_EQ(f5 * f6, Fraction(21, 220));
}

TEST (FractionOperators, TestGreaterThanOperator){
    Fraction f1(1, 5);
    Fraction f2(2, 5);
    ASSERT_TRUE(f2 > f1);

    f1 = Fraction(6, 10);
    ASSERT_TRUE(f1 > f2);

    f1 = Fraction(1, 3);
    f2 = Fraction(5, 6);
    ASSERT_TRUE(f2 > f1);

    f1 = Fraction(3, 7);
    f2 = Fraction(10, 13);
    ASSERT_TRUE(f2 > f1);
}

TEST (FractionOperators, TestLessThanOperator){
    Fraction f1(1, 5);
    Fraction f2(2, 5);
    ASSERT_TRUE(f1 < f2);

    f1 = Fraction(5, 10);
    ASSERT_TRUE(f2 < f1);

    f1 = Fraction(2, 5);
    f2 = Fraction(6, 10);
    ASSERT_TRUE(f1 < f2);

    f1 = Fraction(6, 7);
    f2 = Fraction(4, 17);
    ASSERT_TRUE(f1 < f2);
}

TEST(FractionFunctions, SimplifyFunction){
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