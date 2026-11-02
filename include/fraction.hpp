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

    //implements the << operator (friend function because otherwise, "this" would be implied as first param, can only have 2 params)
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f){
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    //simplifies the fraction
    void simplify(){
        int greatestCommonDivisor = std::gcd(numerator, denominator);
        numerator /= greatestCommonDivisor;
        denominator /= greatestCommonDivisor;

        if (numerator < 0 && denominator < 0){
            numerator *= -1;
            denominator *= -1;
        }
    }
};