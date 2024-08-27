#include "Rook.h"

Rook::Rook(Position position, Color color)
    : chessPiece(PieceType::ROOK, position, color) {}

bool Rook::isValidMove(Position newPosition,
                       const std::vector<std::vector<chessPiece*>>& squares) const
{
    // Rook can only move horizontally or vertically
    if (position.x != newPosition.x && position.y != newPosition.y)
    {
        return false;
    }

    // Horizontal move
    if (position.x == newPosition.x)
    {
        int dir = position.y < newPosition.y ? 1 : -1;
        for (int y = position.y + dir; y != newPosition.y; y += dir)
        {
            if (squares[y][position.x] != nullptr)
            {
                return false; // There's a piece blocking the way
            }
        }
    }
    // Vertical move
    else
    {
        int dir = position.x < newPosition.x ? 1 : -1;
        for (int x = position.x + dir; x != newPosition.x; x += dir)
        {
            if (squares[position.y][x] != nullptr)
            {
                return false; // There's a piece blocking the way
            }
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

void Rook::addMove(){}
