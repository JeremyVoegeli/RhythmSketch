#include "fraction.hpp"
#include <gtest/gtest.h>

TEST(FractionTest, PositiveNums){
    Fraction f(1, 2);

    EXPECT_EQ(f.numerator, 1);
    EXPECT_EQ(f.denominator, 2);
}