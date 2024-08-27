#include "chessPiece.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string chessPiece::toChar() const
{
    if (color == WHITE)
    {
        switch (type)
        {
        case KING:
            return "\u2654 ";
        case QUEEN:
            return "\u2655 ";
        case ROOK:
            return "\u2656 ";
        case BISHOP: 
            return "\u2657 ";
        case KNIGHT:
            return "\u2658 ";
        case PAWN:
            return "\u2659 ";
        default:
            return " ";
        }
    }
    else if (color == BLACK)
    {
        switch (type)
        {
        case KING:
            return "\u265a ";
        case QUEEN:
            return "\u265b ";
        case ROOK:
            return "\u265c ";
        case BISHOP:
            return "\u265d ";
        case KNIGHT:
            return "\u265e ";
        case PAWN:
            return "\u265f ";
        default:
            return " ";
        }
    }
    return " ";
}

chessPiece::chessPiece(PieceType t, Position pos, Color c)
    : type(t), position(pos), color(c)
{
}

void chessPiece::print()
{
    cout << toChar();
}

PieceType chessPiece::getPiece()
{
    return type;
}

Position chessPiece::getPosition()
{
    return position;
}

Color chessPiece::getColor()
{
    return color;
}

void chessPiece::addPossibleMove(const string& move)
{
    possibleMoves.push_back(move);
}

vector<string>& chessPiece::getPossibleMoves() 
{
    return possibleMoves;
}
