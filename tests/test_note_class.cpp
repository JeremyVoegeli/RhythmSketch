#include "note.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(NoteTest, TestConstructor){
    Note n1(
        Fraction(1, 4),
        Sticking::L,
        NoteType::note
    );

    EXPECT_EQ(n1.duration, Fraction(1, 4));
    EXPECT_EQ(n1.sticking, Sticking::L);
    EXPECT_EQ(n1.type, NoteType::note);

    Note n2(
        Fraction(1, 8),
        Sticking::R,
        NoteType::rest
    );

    EXPECT_EQ(n2.duration, Fraction(1, 8));
    EXPECT_EQ(n2.sticking, Sticking::none);
    EXPECT_EQ(n2.type, NoteType::rest);
}

TEST(NoteTest, TestStreamInsertionOperator){
    Note n1(
        Fraction(1, 4),
        Sticking::L,
        NoteType::note
    );

    std::stringstream ss;
    ss << n1;

    EXPECT_EQ(ss.str(), "1/4 note (L)");

    ss.str(""); //clears the value from the SS

    Note n2(
        Fraction(1, 8),
        Sticking::R,
        NoteType::rest
    );

    ss << n2;

    EXPECT_EQ(ss.str(), "1/8 note rest");
}