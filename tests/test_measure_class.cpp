#include "measure.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

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

    m.addNote(Note(Fraction(1, 4), Sticking::none, NoteType::rest));
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

TEST(MeasureTest, TestFillMeasureFunction){
    Measure m1;
    m1.fillMeasure();
    ASSERT_TRUE(std::ranges::contains(m1.notes, Note(Fraction(1, 1), Sticking::none, NoteType::rest)));
    ASSERT_EQ(m1.fullness, Fraction(1, 1));
    ASSERT_EQ(m1.notes.size(), 1);

    Measure m2;
    m2.addNote(Note(Fraction(1, 4), Sticking::R, NoteType::note));
    m2.fillMeasure();

    ASSERT_TRUE(std::ranges::contains(m2.notes, Note(Fraction(1, 4), Sticking::none, NoteType::rest)));
    ASSERT_TRUE(std::ranges::contains(m2.notes, Note(Fraction(1, 2), Sticking::none, NoteType::rest)));
    ASSERT_EQ(m2.fullness, Fraction(1, 1));
    ASSERT_EQ(m2.notes.size(), 3);

    Measure m3;
    m3.addNote(Note(Fraction(1, 16), Sticking::R, NoteType::rest));
    m3.fillMeasure();

    ASSERT_TRUE(std::ranges::contains(m3.notes, Note(Fraction(1, 16), Sticking::none, NoteType::rest)));
    ASSERT_TRUE(std::ranges::contains(m3.notes, Note(Fraction(1, 8), Sticking::none, NoteType::rest)));
    ASSERT_TRUE(std::ranges::contains(m3.notes, Note(Fraction(1, 4), Sticking::none, NoteType::rest)));
    ASSERT_TRUE(std::ranges::contains(m3.notes, Note(Fraction(1, 2), Sticking::none, NoteType::rest)));
    ASSERT_EQ(m3.fullness, Fraction(1, 1));
    ASSERT_EQ(m3.notes.size(), 5);
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