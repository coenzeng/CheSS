#include "king.h"

King::King(bool isWhitePiece): Piece(isWhitePiece){};  

char King::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'Q';
    } else {
        return 'q';
    }
};
bool King::isValidMove(int startRow, int startCol, int endRow, int endCol)
{
    return true;
};

King::~King(){};