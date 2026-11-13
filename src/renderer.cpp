#include "renderer.hpp"

void render(Pattern p){
    std::string output = "";

    //iterates through every measure in the pattern
    for (const auto& measure : p.measures){
        output += "| ";
        int curDepth = 0;

        //iterates through every note in the current measure
        for(const auto& note : measure.notes){

            //base cases for half and whole notes hardcoded
            if (note.duration == Fraction(1, 1)){
                output += "((" + sticking_to_string(note.sticking) + "))";
            }
            else if (note.duration == Fraction(1, 2)) {
                output += "(" + sticking_to_string(note.sticking) + ")";
            }
            else {
                while(curDepth < note.depth){
                    output += "[";
                    curDepth++;
                }

                while(curDepth > note.depth){
                    output += "]";
                    curDepth--;
                }
                
                output += sticking_to_string(note.sticking);

                //output += " ";
            }
        }

        output += " |";
    }

    std::cout << output << std::endl;
}