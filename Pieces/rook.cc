#include "rook.h"
#include "../board.h"
#include <cmath>
using namespace std;

Rook::Rook(bool isWhitePiece): Piece(isWhitePiece){};  

char Rook::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'R';
    } else {
        return 'r';
    }
};

bool Rook::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    // only vertical or horizontal moves allowed
    if (!(startRow == endRow || startCol == endCol)){
        return false;
    }
    int directionX, directionY; 
    directionX = signbit(startCol - endCol) ? 1 : -1; // 1 refers to traversing rightward
    directionY = signbit(startRow - endRow) ? 1 : -1; // 1 refers to tranversing downward
    
    if (startRow - endRow == 0){
        directionY = 0; // moving horizontally
    }else{
        directionX = 0; // moving vertically
    }
    int pathLength = 0;

    pathLength = max(abs(startCol - endCol), abs(startRow - endRow));
    
    // Either directionX or directionY is 0, and the other is -1 or 1
    for(int i = 0; i < pathLength - 1; i++){
        int indX = startCol + directionX; // one of them will stay constant
        int indY = startRow + directionY;
        if(board->getPiece(indY, indX)->charAt(indY, indX) !=  ' '){
            return false;
        }
    }

    return true;
};

Rook::~Rook(){};