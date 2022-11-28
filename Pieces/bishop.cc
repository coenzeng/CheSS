#include "bishop.h"

Bishop::Bishop(bool isWhitePiece): Piece(isWhitePiece){};  

char Bishop::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'B';
    } else {
        return 'b';
    }
};
bool Bishop::isValidMove(int startRow, int startCol, int endRow, int endCol)
{
    return true;
};

Bishop::~Bishop(){};