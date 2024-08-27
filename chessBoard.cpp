#include "chessBoard.h"

#include <iostream>

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

chessBoard::chessBoard() {

    // Initialize the entire board to nullptr
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            board[i][j] = nullptr;
        }
    }
    
    // Set pieces on board
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
           
            if (i == 0)
            {
                if (j == 0 || j == 7)
                {
                    board[i][j] = new Rook(Position{i, j}, BLACK);
                }
                else if (j == 1 || j == 6)
                {
                    board[i][j] = new Knight(Position{i, j}, BLACK);
                }
                else if (j == 2 || j == 5)
                {
                    board[i][j] = new Bishop(Position{i, j}, BLACK);
                }
                else if (j == 3)
                {
                    board[i][j] = new Queen(Position{i, j}, BLACK);
                }
                else if (j == 4)
                {
                    board[i][j] = new King(Position{i, j}, BLACK);
                }
            }
            else if (i == 1)
            {
                board[i][j] = new Pawn(Position{i, j}, BLACK);
            }
            else if (i == 6)
            {
                board[i][j] = new Pawn(Position{i, j}, WHITE);
            }
            else if (i == 7)
            {
                if (j == 0 || j == 7)
                {
                    board[i][j] = new Rook(Position{i, j}, WHITE);
                }
                else if (j == 1 || j == 6)
                {
                    board[i][j] = new Knight(Position{i, j}, WHITE);
                }
                else if (j == 2 || j == 5)
                {
                    board[i][j] = new Bishop(Position{i, j}, WHITE);
                }
                else if (j == 3)
                {
                    board[i][j] = new Queen(Position{i, j}, WHITE);
                }
                else if (j == 4)
                {
                    board[i][j] = new King(Position{i, j}, WHITE);
                }
            }
        }
    }
};


chessBoard::~chessBoard() {

};

void chessBoard::displayBoard(){

const int size = 8;
const int squareWidth = 4;
const int squareHeight = 2;

std::cout << " " << std::endl;
    
    // Top border
    std::cout << "  ┌────────────────────────────────────────────────┐" << std::endl;

    // Main loop for each row
    for (int i = 0; i < size; i++) 
    {
        for (int h = 0; h < squareHeight; h++) 
        {
            // Display row numbers
            if (h == squareHeight / 2) 
            {
                std::cout << (8 - i) << " │";
            } 
            else 
            {
                std::cout << "  │";
            }

            for (int j = 0; j < size; j++) 
            {
                bool isDarkSquare = (i + j) % 2;
                bool isPieceRow = (h == squareHeight / 2);

                // Print the first half of the square.
                for (int w = 0; w < squareWidth / 2 - 1; w++) 
                {
                    std::cout << (isDarkSquare ? "██" : "  ");
                }

                // If it's the row where the chess piece should be displayed and there's a piece.
                if (isPieceRow && board[i][j] != nullptr) 
                {
                    std::cout << board[i][j]->toChar();
                   
                } 
                else 
                {
                    std::cout << (isDarkSquare ? "██" : "  ");
                }

                // Fill the remaining half of the square after the piece.
                for (int w = 0; w < squareWidth / 2 - 1; w++) 
                {
                    std::cout << (isDarkSquare ? "██" : "  ");
                }
            }

            std::cout << "│" << std::endl;
        }
    }

    // Bottom border
    std::cout << "  └────────────────────────────────────────────────┘" << std::endl;
    std::cout << "     a     b     c     d     e     f     g     h   " << std::endl;
    std::cout << " " << std::endl;
};


bool chessBoard::isValidMove(const std::string& from, const std::string& to) {
    // Convert notation to array indices.
    int fromX = from[0] - 'a';
    int fromY = 8 - (from[1] - '0');

    int toX = to[0] - 'a';
    int toY = 8 - (to[1] - '0');

    // Check boundaries
    if (fromX < 0 || fromX >= size || fromY < 0 || fromY >= size ||
        toX < 0 || toX >= size || toY < 0 || toY >= size)
    {
        return false;
    }
    
    // Check if there's a piece at the starting position.
    if (board[fromY][fromX] == nullptr) 
    {
        return false;
    }

    std::vector<std::vector<chessPiece*>> squares(size, std::vector<chessPiece*>(size));
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            squares[i][j] = board[i][j];
        }
    }

    return board[fromY][fromX]->isValidMove(Position{toY, toX}, squares);
}


void chessBoard::makeMove(const std::string& from, const std::string& to)
{
    //change notation to row and column
    int fromX = from[0] - 'a';
    int fromY = 8 - (from[1] - '0');

    int toX = to[0] - 'a';
    int toY = 8 - (to[1] - '0');

    // Move piece from start to end position.
    board[toY][toX] = board[fromY][fromX];
    
    // Set the start position to nullptr (blank square)
    board[fromY][fromX] = nullptr;
}





