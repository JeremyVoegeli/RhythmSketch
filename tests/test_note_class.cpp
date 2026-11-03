#include "note.hpp"
#include <gtest/gtest.h>

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
    EXPECT_EQ(n2.sticking, Sticking::space);
    EXPECT_EQ(n2.type, NoteType::rest);
}