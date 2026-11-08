#pragma once
#include <iostream>
#include <numeric>
#include <stdexcept>

class Fraction{
public:

    int numerator;
    int denominator;

    //default constructor
    Fraction (){
        numerator = 1;
        denominator = 2;
    }

    //Custom constructor
    Fraction(int n, int d){
        numerator = n;
        denominator = d;

        //check for 0 denominator
        if (denominator == 0){
            throw std::invalid_argument("Error: Cannot have a 0 denominator");
        }
    }

    bool operator==(const Fraction& other) const;

    Fraction& operator+=(const Fraction& other);

    friend Fraction operator+(Fraction lhs, const Fraction& rhs);

    Fraction& operator-=(const Fraction& other);

    friend Fraction operator-(Fraction lhs, const Fraction& rhs);

    friend bool operator>(const Fraction& lhs, const Fraction& rhs);

    friend bool operator<(const Fraction& lhs, const Fraction& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

    //simplifies the fraction
    void simplify();
};