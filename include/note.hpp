#pragma once
#include "fraction.hpp"
#include <iostream>

enum class Sticking {
    R,
    L,
    space
};

inline std::ostream& operator<<(std::ostream& os, const Sticking& s){
    switch (s) {
        case Sticking::R:
            os << "R";
            break;
        case Sticking::L:
            os << "L";
            break;
        case Sticking::space:
            os << " ";
            break;
    }
    
    return os;
}

enum class NoteType {
    rest,
    note
};

class Note {
public:
    Fraction duration;
    Sticking sticking;
    NoteType type;

    Note(Fraction d, Sticking s, NoteType t){
        duration = d;
        sticking = s;
        type = t;
    }

    friend std::ostream& operator<<(std::ostream& os, const Note& n){
        os << n.duration << " note";
        if (n.type == NoteType::rest){
            os << " rest";
        } else {
            os << " (" << n.sticking << ")";
        }
        return os;
    }
};