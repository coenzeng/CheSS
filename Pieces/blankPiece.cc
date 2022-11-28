#include "blankPiece.h"

BlankPiece::BlankPiece(bool isWhitePiece): Piece(isWhitePiece){};  

char BlankPiece::charAt(int row, int col)
{
    return ' ';
};
bool BlankPiece::isValidMove(int startRow, int startCol, int endRow, int endCol)
{
    return true;
};

BlankPiece::~BlankPiece(){};