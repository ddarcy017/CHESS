#include "Bishop.h"
#include <cmath>

Bishop::Bishop(Position position, Color color)
    : chessPiece(PieceType::BISHOP, position, color) {}

bool Bishop::isValidMove(Position newPosition,
         const std::vector<std::vector<chessPiece*>>& squares) const
{
    // Check for diagonal move
    if (std::abs(newPosition.x - position.x) != std::abs(newPosition.y - position.y))
    {
        return false;
    }

    // Determine direction of movement
    int xDirection = (newPosition.x > position.x) ? 1 : -1;
    int yDirection = (newPosition.y > position.y) ? 1 : -1;

    int x, y;
    for (x = position.x + xDirection, y = position.y + yDirection; 
         x != newPosition.x; 
         x += xDirection, y += yDirection)
    {
        if (squares[y][x] != nullptr)
        {
            return false; // A piece is blocking the path
        }
    }

    // Ensure we aren't capturing a piece of our own color
    if (squares[newPosition.y][newPosition.x] != nullptr &&
        squares[newPosition.y][newPosition.x]->getColor() == color)
    {
        return false;
    }

    return true;
}

void Bishop::addMove()
{
    // Implementation details (you might want to add logic here in the future)
}
