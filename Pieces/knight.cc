#include "knight.h"

Knight::Knight(bool isWhitePiece): Piece(isWhitePiece){};  

char Knight::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'N';
    } else {
        return 'n';
    }
};
bool Knight::isValidMove(int startRow, int startCol, int endRow, int endCol)
{
    return true;
};

Knight::~Knight(){};