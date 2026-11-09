#include <vector>
#include "note.hpp"

class Measure{
public:
    std::vector<Note> notes; //stack of all notes in the measure
    Fraction timeSignature = Fraction(4, 4);
    Fraction fullness = Fraction(0,1);

    Measure();

    Measure(Fraction timeSig){
        timeSignature = timeSig;
    }

    void addNote(Note note);

    void removeNote();
};