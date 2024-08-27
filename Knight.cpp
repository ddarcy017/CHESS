#include "Knight.h"

Knight::Knight(Position position, Color color)
    : chessPiece(PieceType::KNIGHT, position, color) {}

bool Knight::isValidMove(Position newPosition,
                         const std::vector<std::vector<chessPiece*>>& squares) const
{
    int dx = abs(newPosition.x - position.x);
    int dy = abs(newPosition.y - position.y);

    // Knights move in an L-shape (2 squares in one direction, 1 square perpendicular).
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

void Knight::addMove()
{
    // Implementation details (you might want to add logic here in the future)
}
