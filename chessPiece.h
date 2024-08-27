#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include <vector>
#include <string>
using namespace std;

#include "Position.h"

enum Color
{
  NONE,
  WHITE,
  BLACK
};

enum PieceType
{
  EMPTY,
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN
};

class chessPiece
{
public:
  chessPiece(PieceType t, Position pos, Color c);
  virtual ~chessPiece() = default;

  virtual bool isValidMove(
      Position newPosition,
      const std::vector<std::vector<chessPiece*>>& squares) const = 0;

  string toChar() const;
  void print();
  PieceType getPiece();
  Position getPosition();
  Color getColor();

  void addPossibleMove(const string& move);             // Declared here
  vector<string>& getPossibleMoves();                   // Declared here

  virtual void addMove() = 0;

protected:
  PieceType type;
  Position position;   // Ensure these are protected for derived class access
  Color color;
  vector<string> possibleMoves;
};

#endif // CHESSPIECES_H
