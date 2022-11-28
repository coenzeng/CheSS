#include "pawn.h"

Pawn::Pawn(bool isWhitePiece): Piece(isWhitePiece){};  

char Pawn::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'P';
    } else {
        return 'p';
    }
};
bool Pawn::isValidMove(int startRow, int startCol, int endRow, int endCol)
{
    return true;
};

Pawn::~Pawn(){};