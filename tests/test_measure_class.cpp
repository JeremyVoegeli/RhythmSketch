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

TEST(MeasureTest, TestAddNoteFunction){
    Measure m;

    m.addNote(Note(Fraction(1, 4), Sticking::R, NoteType::note));
    EXPECT_EQ(m.fullness, Fraction(1, 4));
    EXPECT_EQ(m.notes.size(), 1);

    m.addNote(Note(Fraction(1, 2), Sticking::L, NoteType::note));
    EXPECT_EQ(m.fullness, Fraction(3, 4));
    EXPECT_EQ(m.notes.size(), 2);

    m.addNote(Note(Fraction(1, 4), Sticking::space, NoteType::rest));
    EXPECT_EQ(m.fullness, (Fraction(1, 1)));
    EXPECT_EQ(m.notes.size(), 3);

    ASSERT_THROW(m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note)), std::logic_error);
}