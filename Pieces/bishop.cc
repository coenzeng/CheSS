#include "bishop.h"
#include "../board.h"
#include <cmath>

using namespace std;

Bishop::Bishop(bool isWhitePiece): Piece(isWhitePiece){};  

char Bishop::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'B';
    } else {
        return 'b';
    }
};
bool Bishop::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    int rowDiff = startRow - endRow; // vertical difference (Y)
    int colDiff = startCol - endCol; // horizontal difference (X)

    // not diagonal
    if (abs(rowDiff) != abs(colDiff)){
        return false;
    }
    int pathLength = abs(rowDiff);

    // check all blocks in board until final location (determine direction)
    int directionX, directionY; 
    directionX = signbit(colDiff) ? 1 : -1; // 1 refers to traversing rightward
    directionY = signbit(rowDiff) ? 1 : -1; // 1 refers to traversing downward

    for(int i = 0; i < pathLength; i++){
        int indX = startCol + directionX; 
        int indY = startRow + directionY;
        if(board->getPiece(indX, indY)->charAt(indX, indY) !=  ' '){
            return false;
        }
    }
    
    return true;
};

Bishop::~Bishop(){};
