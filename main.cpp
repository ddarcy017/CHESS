#include <iostream>


#include "chessBoard.h"

int main() {
  std::string fromPos, toPos;
  std::string option;

  chessBoard board;
 

  while (true) {
    // Calling methods in board object
    board.displayBoard();

    std::cout << "Enter your move (e.g., e2 e4): ";
    std::cin >> fromPos >> toPos;

    if (fromPos == "exit") {
      break;
    }

    if (board.isValidMove(fromPos, toPos)) {
      board.makeMove(fromPos, toPos);
    } else {
      std::cout << "Invalid move. Try again." << std::endl;
    }
  }

  return 0;
};

