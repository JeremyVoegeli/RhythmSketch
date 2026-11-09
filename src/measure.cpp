#include "measure.hpp"
#include <cmath>

namespace {
    bool isPowerOfTwo(int n){
        double log = std::log2(n);
        return (std::floor(log) == log);
    }
}

Measure::Measure() {};

Measure::Measure(Fraction timeSig){
    timeSignature = timeSig;
}

void Measure::addNote(Note note){
    //Check that there is enough space in the measure to hold the new note
    if (fullness + note.duration > timeSignature){
        throw std::logic_error("Error: Not enough room in the measure remaining to add this note");
    }

    // ***********************************************************
    // TEMPORARY - Forces duple meter notes only
    // ***********************************************************

    if (note.duration.numerator != 1 || !isPowerOfTwo(note.duration.denominator)){
        throw std::runtime_error("Error: Program does not support notes that are not powers of 2 (1/2, 1/4, 1/8, etc.)");
    }

    //update the measure's fullness
    fullness += note.duration;

    //add the note to the measure's stack of notes
    notes.push_back(note);
}

void Measure::removeNote() {
    //Check that the measure is not empty before attempting to remove a note
    if (notes.empty()){
        throw std::out_of_range("Error: Measure is empty, cannot remove any notes");
    }
    
    //retrieve the last note
    Note lastNote = notes.back();
    
    //update the measure's fullness
    fullness -= lastNote.duration;

    //remove the note from the measure's stack of notes
    notes.pop_back();
}