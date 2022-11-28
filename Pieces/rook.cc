#include "rook.h"

Rook::Rook(bool isWhitePiece): Piece(isWhitePiece){};  

char Rook::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'R';
    } else {
        return 'r';
    }
};
bool Rook::isValidMove(int startRow, int startCol, int endRow, int endCol)
{
    if (startRow == endRow || startCol == endCol)
    {
        return true;
    }
    return false;
};

Rook::~Rook(){};