#include <iostream>
#include "terminal_utils.hpp"
#include "renderer.hpp"

int main(){
    enableRawMode();

    Pattern p;
    Measure m;
    p.addMeasure(m);

    std::cout << "Raw mode active. (q or CMD + Q to quit.)\r\n";

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1){
        if (c == 'q' || c == 17){
            break;
        }

        if (c >= 32 && c <= 126){
            std::cout << c << "\r\n";
        }

        //add R note
        else if (c == 82 || c == 114){
            m.addNote(Note(Fraction(1, 8), Sticking::R, NoteType::note));
            std::cout << render(p) << std::endl;
        }

        //add L note
        else if (c == 76 || c == 108){
            m.addNote(Note(Fraction(1, 8), Sticking::L, NoteType::note));
            std::cout << render(p) << std::endl;
        }
    }
}