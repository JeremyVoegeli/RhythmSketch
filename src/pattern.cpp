#include "pattern.hpp"

Pattern::Pattern() {};

void Pattern::addMeasure(Measure measure){
    //fills measure with rests to complete it
    measure.fillMeasure();

    //adds note to measure marking end of measure
    measure.addNote(Note(Fraction(0, 4), Sticking::none, NoteType::endOfMeasure));
    
    measures.push_back(measure);
}

void Pattern::removeMeasure(){
    //Check that measures vector isn't empty
    if (measures.empty()){
        throw std::out_of_range("Error: Pattern is empty, cannot remove any measures");
    }

    measures.pop_back();
}