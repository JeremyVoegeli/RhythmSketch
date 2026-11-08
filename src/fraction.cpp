#include "fraction.hpp"

bool Fraction::operator==(const Fraction& other) const {
    return (numerator == other.numerator && denominator == other.denominator);
}

Fraction& Fraction::operator+=(const Fraction& other){
    //Find lowest common multiple
    int lowestCommonMultiple = std::lcm(denominator, other.denominator);

    //Multiply this.fraction to get denominator as LCM
    int thisModifier = lowestCommonMultiple / denominator;
    numerator *= thisModifier;
    denominator *= thisModifier;

    //Multiply other.fraction to get denominator as LCM, add numerator to this.numerator
    int otherModifier = lowestCommonMultiple / other.denominator;
    numerator += other.numerator * otherModifier;

    this->simplify();

    return *this;
}

Fraction operator+(Fraction lhs, const Fraction& rhs){
    lhs += rhs;
    return lhs;
}

Fraction& Fraction::operator-=(const Fraction& other){
    //Find lowest common multiple
    int lowestCommonMultiple = std::lcm(denominator, other.denominator);

    //multiply this to get denominator as LCM
    int thisModifier = lowestCommonMultiple / denominator;
    numerator *= thisModifier;
    denominator *= thisModifier;

    //Multiply other.fraction to get denominator as LCM add subtract numerators
    int otherModifier = lowestCommonMultiple / other.denominator;
    numerator -= other.numerator * otherModifier;

    this->simplify();
    return *this;
}

Fraction operator-(Fraction lhs, const Fraction& rhs){
    lhs -= rhs;
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

bool operator<(const Fraction& lhs, const Fraction& rhs){
    //find the least common multiple between both fractions
    int leastCommonMultiple = std::lcm(lhs.denominator, rhs.denominator);

    //Find the numerators of both fractions once multiplied by the LCM
    int lhsCommonNumerator = lhs.numerator * leastCommonMultiple;
    int rhsCommonNumerator = rhs.numerator * leastCommonMultiple;

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