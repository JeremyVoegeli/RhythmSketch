#include <iostream>
#include "terminal_utils.hpp"
#include "pattern.hpp"
#include "renderer.hpp"

int main(){
    
    Measure m;
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 16), Sticking::none, NoteType::rest));
    m.addNote(Note(Fraction(1, 16), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 16), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 16), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
    m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 16), Sticking::R, NoteType::note));
    m.addNote(Note(Fraction(1, 16), Sticking::L, NoteType::note));

    Pattern p;
    p.addMeasure(m);
    render(p);

    return 0;
}




/*
enableRawMode();

    std::cout << "Raw mode active. (q or CMD + Q to quit.)\r\n";

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1){
        if (c == 'q' || c == 17){
            break;
        }

        if (c >= 32 && c <= 126){
            std::cout << c << "\r\n";
        }
    }
*/