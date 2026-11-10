#include <vector>
#include <iostream>
#include "note.hpp"

class Measure{
public:
    std::vector<Note> notes; //stack of all notes in the measure
    Fraction timeSignature = Fraction(4, 4);
    Fraction fullness = Fraction(0,1);

    Measure();

    Measure(Fraction timeSig);

    friend std::ostream& operator<<(std::ostream& os, Measure m);

    void addNote(Note note);

    void removeNote();

    void fillMeasure();
};