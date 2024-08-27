#include "Move.h"
#include <iostream>

Move::Move(const std::string& from, const std::string& to) : from(from), to(to) {}

std::string Move::getFrom() const {
    return from;
}

std::string Move::getTo() const {
    return to;
}

Move getMove() {
    std::string from, to;
    std::cout << "Enter start position: ";
    std::cin >> from;
    std::cout << "Enter destination position: ";
    std::cin >> to;

    return Move(from, to);
}
