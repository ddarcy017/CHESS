#include "Pawn.h"

#include <iostream>

Pawn::Pawn(Position position, Color color)
    : chessPiece(PieceType::PAWN, position, color) {}

bool Pawn::isValidMove(Position newPosition, const std::vector<std::vector<chessPiece*>>& squares) const
{
    int direction = (color == WHITE) ? -1 : 1;
    int startRow = (color == WHITE) ? 6 : 1;
std::cout << "Current Position: " << position.y << ", " << position.x << std::endl;
std::cout << "Target Position: " << newPosition.y << ", " << newPosition.x << std::endl;

    // Single move forward
    if (newPosition.x == position.x && newPosition.y == position.y + direction)
    {
        if (squares[newPosition.y][newPosition.x] == nullptr)
            return true;
    }

    // Capture move
    if ((newPosition.x == position.x + 1 || newPosition.x == position.x - 1) && newPosition.y == position.y + direction)
    {
        if (squares[newPosition.y][newPosition.x] != nullptr && squares[newPosition.y][newPosition.x]->getColor() != color)
            return true;
    }

    // Double move forward from starting position
    if (position.y == startRow && newPosition.x == position.x && newPosition.y == position.y + 2 * direction)
    {
        if (squares[position.y + direction][position.x] == nullptr && squares[newPosition.y][newPosition.x] == nullptr)
            return true;
    }

    return false;
}


void Pawn::addMove()
{
    // Implementation details (you might want to add logic here in the future)
}
