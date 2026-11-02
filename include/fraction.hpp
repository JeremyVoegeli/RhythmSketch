#pragma once
#include <iostream>
#include <numeric>

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
    }

    //implements the << operator (friend function because otherwise, "this" would be implied as first param, can only have 2 params)
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f){
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    //simplifies the fraction
    void simplify(){
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
};