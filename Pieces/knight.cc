#include "knight.h"
#include <cmath>

Knight::Knight(bool isWhitePiece): Piece(isWhitePiece){};  

char Knight::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'N';
    } else {
        return 'n';
    }
};
bool Knight::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    // knight can leap over other pieces, so do not need to check if path is empty
    if(((abs(startRow - endRow) == 1) && (abs(startCol - endCol) == 2)) ||
       ((abs(startRow - endRow) == 2) && (abs(startCol - endCol) == 1))){
        return true;
       }
    return false;
};

Knight::~Knight(){};