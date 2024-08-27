#include "King.h"

King::King(Position position, Color color)
    : chessPiece(PieceType::KING, position, color) {}

bool King::isValidMove(Position newPosition,
                       const std::vector<std::vector<chessPiece*>>& squares) const
{
    int dx = abs(newPosition.x - position.x);
    int dy = abs(newPosition.y - position.y);

    // Check if the move is only one square in any direction
    if ((dx == 1 || dx == 0) && (dy == 1 || dy == 0)) {
        if (squares[newPosition.y][newPosition.x] == nullptr || 
            squares[newPosition.y][newPosition.x]->getColor() != color) {
            return true;
        }
    }

    return false;
}

void King::addMove()
{
    // Implementation details (you might want to add logic here in the future)
}
