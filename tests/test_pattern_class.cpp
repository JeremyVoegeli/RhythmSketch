#include "pattern.hpp"
#include <gtest/gtest.h>

Measure createMeasure(){
    Measure m;
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 4), Sticking::space, NoteType::rest));
    m.addNote(Note(Fraction(1, 2), Sticking::space, NoteType::rest));

    return m;
}

TEST (TestPattern, TestAddMeasureFunction){
    Pattern p;
    EXPECT_TRUE(p.measures.empty());
    
    Measure m = createMeasure();
    p.addMeasure(m);
    EXPECT_EQ(p.measures.size(), 1);

    p.addMeasure(m);
    EXPECT_EQ(p.measures.size(), 2);
}

TEST (TestPattern, TestRemoveMeasureFunction) {
    Pattern p;

    Measure m = createMeasure();
    p.addMeasure(m);
    p.addMeasure(m);

    p.removeMeasure();
    EXPECT_EQ(p.measures.size(), 1);

    p.removeMeasure();
    EXPECT_EQ(p.measures.size(), 0);

    ASSERT_THROW(p.removeMeasure(), std::out_of_range);
}