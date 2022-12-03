#include "blankPiece.h"

BlankPiece::BlankPiece(bool isWhitePiece): Piece(isWhitePiece){};  

char BlankPiece::charAt(int row, int col)
{
    return ' ';
};
bool BlankPiece::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    return true;
};

BlankPiece::~BlankPiece(){};