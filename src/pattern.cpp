#include "pattern.hpp"

Pattern::Pattern() {};

void Pattern::addMeasure(Measure measure){
    //fills measure with rests to complete it
    measure.fillMeasure();
    
    measures.push_back(measure);
}

void Pattern::removeMeasure(){
    //Check that measures vector isn't empty
    if (measures.empty()){
        throw std::out_of_range("Error: Pattern is empty, cannot remove any measures");
    }

    measures.pop_back();
}