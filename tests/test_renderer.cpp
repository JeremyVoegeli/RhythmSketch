#include "renderer.hpp"
#include <gtest/gtest.h>

TEST (TestRenderer, TestWholeNoteRender){
    Pattern p;
    Measure m;
    m.addNote(Note(Fraction(1, 1), Sticking::R, NoteType::note));
    p.addMeasure(m);

    ASSERT_EQ(render(p), "| ((R)) |");
}

TEST (TestRenderer, TestHalfNoteRender){
    Pattern p;
    Measure m;
    m.addNote(Note(Fraction(1, 2), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 2), Sticking::L, NoteType::note));
    p.addMeasure(m);

    ASSERT_EQ(render(p), "| (R)(L) |");
}

TEST (TestRenderer, TestQuarterNoteRender){
    Pattern p;
    Measure m;
    m.addNote(Note(Fraction(1, 4), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 4), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 4), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 4), Sticking::L, NoteType::note));
    p.addMeasure(m);

    ASSERT_EQ(render(p), "| RLRL |");
}

TEST (TestRenderer, TestEightNoteRender){
    Pattern p;
    Measure m;
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
    p.addMeasure(m);

    ASSERT_EQ(render(p), "| [RLRRLRLL] |");
}