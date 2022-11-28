#include "queen.h"

Queen::Queen(bool isWhitePiece): Piece(isWhitePiece){};  

char Queen::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'Q';
    } else {
        return 'q';
    }
};
bool Queen::isValidMove(int startRow, int startCol, int endRow, int endCol)
{
    return true;
};

Queen::~Queen(){};