#include <iostream>
#include "fraction.hpp"

int main(){
    Fraction f(2, 0);

    f.simplify();
    std::cout << f << std::endl;

    return 0;
}