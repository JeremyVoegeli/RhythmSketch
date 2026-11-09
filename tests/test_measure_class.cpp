#include "measure.hpp"
#include <gtest/gtest.h>

TEST(MeasureTest, TestConstructor){
    Measure m1;
    EXPECT_TRUE(m1.notes.empty());
    EXPECT_EQ(m1.timeSignature, Fraction(4, 4));
    EXPECT_EQ(m1.fullness, Fraction(0, 1));

    Measure m2(Fraction(3, 4));
    EXPECT_TRUE(m2.notes.empty());
    EXPECT_EQ(m2.timeSignature, Fraction(3, 4));
    EXPECT_EQ(m2.fullness, Fraction(0, 1));
}