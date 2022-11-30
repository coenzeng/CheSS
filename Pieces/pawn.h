#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include <iostream>

class Pawn: public Piece {
    public: 
        Pawn(bool isWhite);  
        ~Pawn();
        char charAt(int row, int col);
        bool isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer);
};

#endif