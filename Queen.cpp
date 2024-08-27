#include "Queen.h"

Queen::Queen(Position position, Color color)
    : chessPiece(PieceType::QUEEN, position, color) {}

bool Queen::isValidMove(Position newPosition,
                       const std::vector<std::vector<chessPiece*>>& squares) const
{
    int dx = abs(newPosition.x - position.x);
    int dy = abs(newPosition.y - position.y);

    // Queen can move in any direction (horizontally, vertically, or diagonally).
    return (position.x == newPosition.x || position.y == newPosition.y) || (dx == dy);
}

void Queen::addMove()
{
    // Implementation details (you might want to add logic here in the future)
}
