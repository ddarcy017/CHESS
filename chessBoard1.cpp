#include "chessBoard.h"

#include <iostream>

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

chessBoard::chessBoard() {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i == 0) {
        // Initialize black pieces in the first row
        if (j == 0 || j == 7) {
          board[i][j] = new Rook(Position{i, j}, BLACK);
        } else if (j == 1 || j == 6) {
          board[i][j] = new Knight(Position{i, j}, BLACK);
        } else if (j == 2 || j == 5) {
          board[i][j] = new Bishop(Position{i, j}, BLACK);
        } else if (j == 3) {
          board[i][j] = new Queen(Position{i, j}, BLACK);
        } else if (j == 4) {
          board[i][j] = new King(Position{i, j}, BLACK);
        }
      } else if (i == 1) {
        // Initialize black pawns in the second row
        board[i][j] = new Pawn(Position{i, j}, BLACK);
      } else if (i == 6) {
        // Initialize white pawns in the seventh row
        board[i][j] = new Pawn(Position{i, j}, WHITE);
      } else if (i == 7) {
        // Initialize white pieces in the eighth row
        if (j == 0 || j == 7) {
          board[i][j] = new Rook(Position{i, j}, WHITE);
        } else if (j == 1 || j == 6) {
          board[i][j] = new Knight(Position{i, j}, WHITE);
        } else if (j == 2 || j == 5) {
          board[i][j] = new Bishop(Position{i, j}, WHITE);
        } else if (j == 3) {
          board[i][j] = new Queen(Position{i, j}, WHITE);
        } else if (j == 4) {
          board[i][j] = new King(Position{i, j}, WHITE);
        }
      }
    }
  }
}

chessBoard::~chessBoard() {}

void chessBoard::displayBoard() {

//Initialise
const int size = 8;   
const int squareWidth  = 6;  
const int squareHeight = 3; 

const int consoleWidth = 80;  // Assume console width 
const int boardWidth = size * squareWidth + 4;  // +2 for left numbers, +2 for vertical borders
const int spacing = (consoleWidth - boardWidth) / 2;

const int space = 2;  // Initialise space

// Add space above 
    for (int i = 0; i < space; i++) {
        std::cout << std::endl;
    }

// Top border
    for (int p = 0; p < spacing; p++) {
    std::cout << " ";
    }
    
   std::cout << "  " << "┌";  // topRight corner

    for (int j = 0; j < size * squareWidth; j++) {
        std::cout << "─";
    }
   
    std::cout << "┐" << "  " << std::endl; // topLeft corner

// Main loop 
for (int i = 0; i < size; i++) {
    for (int h = 0; h < squareHeight; h++) {
        for (int p = 0; p < spacing; p++) {
            std::cout << " ";
        }

        // Row nums (8-1) 
        if (h == squareHeight / 2 - 1) {
            std::cout << (8 - i) << " ";
        } else {
            std::cout << "  ";
        }

        std::cout << "│";

        for (int j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {  // For white squares
                for (int w = 0; w < squareWidth / 2 - 1; w++) {  // Print half spaces
                    std::cout << " ";
                }
                if (board[i][j] != nullptr && h == squareHeight / 2 - 1) {
                    std::cout << board[i][j]->toChar();
                    board[i][j]->addMove();  // Print piece if exists
                } else {
                    std::cout << " ";  // Or space if no piece
                }
                for (int w = 0; w < squareWidth / 2; w++) {
                    std::cout << " ";  // Print the remaining half spaces
                }
            } else {  // For black squares
                for (int w = 0; w < squareWidth; w++) {
                    std::cout << "█";
                }
            }
        }

        std::cout << "│";
        std::cout << "  " << std::endl;
    }
}



// Bottom border
    for (int p = 0; p < spacing; ++p) {
     std::cout << " ";
    }
    
    std::cout << "  " << "└"; // bottomLeft corner
    
    for (int j = 0; j < size * squareWidth; ++j) {
        std::cout << "─";
    }
    
    std::cout << "┘" << std::endl; // bottomRight corner

// Print chars (a-h) 
    for (int p = 0; p < spacing + 1; ++p) {
        std::cout << " ";
    }
    
    for (char c = 'a'; c <= 'h'; ++c) {
        std::cout << std::string((squareWidth + 1) / 2 - 1 , ' ') << c << std::string(squareWidth / 2, ' ');
    }
    
    std::cout << std::endl;

// Add space below 
    for (int i = 0; i < space; ++i) {
        std::cout << std::endl;
    }

};

   
