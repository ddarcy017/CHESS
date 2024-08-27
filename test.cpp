#include <iostream>
#include <string>
using namespace std;

#include "Position.h"
#include "LoggingBoard.h"
#include "chessBoard.h"
#include "Bishop.h"
#include "chessPiece.h"
int main() {

// std::cout << "Hello, World!" << std::endl;
// string from = "e8";
// string to = "g7";
//   int fromX = from[0] - 'a';
//     int fromY = 8 - (from[1] - '0');

//     int toX = to[0] - 'a';
//     int toY = 8 - (to[1] - '0');
// //    char col = 'a' + fromX;
// //     char row = '8' - fromY;

// //     cout <<string(1, col) + string(1, row); 
//     cout << fromX << endl << fromY <<endl << toX << endl << toY << endl;
//     // for(string a = "a"; a < "h"; a + 'a'){
//     //     cout<< a << endl;
//     // };
    
//     cout << 'e' - 'a' ;

    chessPiece* bishop = new Bishop(Position{2,5}, BLACK);
    bishop->addMove();
    for (unsigned int i = 0; i < bishop->getPossibleMoves().size(); i++)
    {
        cout << bishop->getPossibleMoves()[i] << " ";
    }
    delete bishop;
};

    
