#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "chessPiece.h"

class chessBoard {
 public:
  chessBoard();
  ~chessBoard();

void displayBoard();
bool isValidMove(const std::string& from, const std::string& to);
void makeMove(const std::string& from, const std::string& to);

 private:
  static const int size = 8;
  chessPiece* board[8][8];
};

#endif  
