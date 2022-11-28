#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include <iostream>

class Pawn: public Piece {
    public: 
        Pawn(bool isWhite);  
        ~Pawn();
        char charAt(int row, int col);
        bool isValidMove(int startRow, int startCol, int endRow, int endCol);
};

#endif