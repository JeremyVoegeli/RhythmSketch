#include <iostream>
#include "measure.hpp"

int main(){
    Measure m;
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));

    std::cout << m << std::endl;

    m.fillMeasure();

    std::cout << m << std::endl;

    return 0;
}