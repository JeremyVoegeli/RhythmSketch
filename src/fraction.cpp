#include "fraction.hpp"

bool Fraction::operator==(const Fraction& other) const {
    return (numerator == other.numerator && denominator == other.denominator);
}

Fraction& Fraction::operator+=(const Fraction& other){
    //Find lowest common multiple
    int leastCommonMultiple = std::lcm(denominator, other.denominator);

    //modify this.fraction to have a denominator = LCM, get numerator when this is done
    int thisModifier = leastCommonMultiple / denominator;
    int thisNumeratorModified = numerator * thisModifier;

    //modify other.fraction to have a denominator = LCM, get numerator when this is done
    int otherModifier = leastCommonMultiple / other.denominator;
    int otherNumeratorModified = other.numerator * otherModifier;

    //sum modified numerators together, set denominator to LCM
    numerator = thisNumeratorModified + otherNumeratorModified;
    denominator = leastCommonMultiple;

    this->simplify();
    return *this;
}

Fraction operator+(Fraction lhs, const Fraction& rhs){
    lhs += rhs;
    return lhs;
}

Fraction& Fraction::operator-=(const Fraction& other){
    //Find lowest common multiple
    int leastCommonMultiple = std::lcm(denominator, other.denominator);

    //modify this.fraction to have a denominator = LCM, get numerator when this is done
    int thisModifier = leastCommonMultiple / denominator;
    int thisNumeratorModified = numerator * thisModifier;

    //modify other.fraction to have a denominator = LCM, get numerator when this is done
    int otherModifier = leastCommonMultiple / other.denominator;
    int otherNumeratorModified = other.numerator * otherModifier;

    //subtract modified numerators , set denominator to LCM
    numerator = thisNumeratorModified - otherNumeratorModified;
    denominator = leastCommonMultiple;

    this->simplify();
    return *this;
}

Fraction operator-(Fraction lhs, const Fraction& rhs){
    lhs -= rhs;
    return lhs;
}

Fraction& Fraction::operator*=(const Fraction& other){
    numerator *= other.numerator;
    denominator *= other.denominator;

    this->simplify();
    return *this;
}

Fraction operator*(Fraction lhs, const Fraction& rhs){
    lhs *= rhs;
    return lhs;
}

bool operator>(const Fraction& lhs, const Fraction& rhs){
    //find the least common multiple between both fractions
    int leastCommonMultiple = std::lcm(lhs.denominator, rhs.denominator);

    //Find the numerators of both fractions once multiplied by the LCM
    int lhsCommonNumerator = lhs.numerator * leastCommonMultiple;
    int rhsCommonNumerator = rhs.numerator * leastCommonMultiple;

    //Compare numerators
    return (lhsCommonNumerator > rhsCommonNumerator);
}

bool operator<(const Fraction& lhs, const Fraction& rhs){
    //find the least common multiple between both fractions
    int leastCommonMultiple = std::lcm(lhs.denominator, rhs.denominator);

    //Find the numerators of both fractions once multiplied by the LCM
    int lhsCommonNumerator = lhs.numerator * (leastCommonMultiple / lhs.denominator);
    int rhsCommonNumerator = rhs.numerator * (leastCommonMultiple / rhs.denominator);

    //Compare numerators
    return (lhsCommonNumerator < rhsCommonNumerator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f){
    os << f.numerator << "/" << f.denominator;
    return os;
}

void Fraction::simplify(){
    int greatestCommonDivisor = std::gcd(numerator, denominator);
    numerator /= greatestCommonDivisor;
    denominator /= greatestCommonDivisor;

    if (numerator < 0 && denominator < 0){
        numerator *= -1;
        denominator *= -1;
    }
}