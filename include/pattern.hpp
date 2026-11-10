#pragma once
#include "measure.hpp"

class Pattern{
public:
    std::vector<Measure> measures;

    Pattern();

    void addMeasure(Measure measure);

    void removeMeasure();
};