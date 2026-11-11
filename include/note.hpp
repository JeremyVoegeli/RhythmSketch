#pragma once
#include "fraction.hpp"
#include <iostream>

enum class Sticking {
    R,
    L,
    none
};

constexpr std::string to_string(Sticking s){
    switch (s){
        case Sticking::R:
            return "R";
            break;
        case Sticking::L:
            return "L";
            break;
        case Sticking::none:
            return "/";
            break;
    }
}

inline std::ostream& operator<<(std::ostream& os, const Sticking& s){
    switch (s) {
        case Sticking::R:
            os << "R";
            break;
        case Sticking::L:
            os << "L";
            break;
        case Sticking::none:
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

        if (t == NoteType::rest) {
            sticking = Sticking::none;
        }
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

    friend bool operator==(Note lhs, Note rhs){
        return (
            lhs.duration == rhs.duration &&
            lhs.sticking == rhs.sticking &&
            lhs.type == rhs.type
        );
    }
};