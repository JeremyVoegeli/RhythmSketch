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

TEST(MeasureTest, TestRemoveNoteFunction){
    Measure m;
    m.addNote(Note(Fraction(1, 2), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 2), Sticking::L, NoteType::note));
    EXPECT_EQ(m.notes.size(), 2);
    EXPECT_EQ(m.fullness, Fraction(1, 1));

    m.removeNote();
    EXPECT_EQ(m.notes.size(), 1);
    EXPECT_EQ(m.fullness, Fraction(1, 2));

    m.removeNote();
    EXPECT_TRUE(m.notes.empty());
    EXPECT_EQ(m.fullness, Fraction(0, 1));

    ASSERT_THROW(m.removeNote(), std::out_of_range);
}

TEST(MeasureTest, TestIsFullFunction){
    Measure m;
    m.addNote(Note(Fraction(1, 4), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 4), Sticking::L, NoteType::note));
    ASSERT_FALSE(m.isFull());

    m.addNote(Note(Fraction(1, 4), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 4), Sticking::L, NoteType::note));
    ASSERT_TRUE(m.isFull());
}