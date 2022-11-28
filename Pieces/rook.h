#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include <iostream>

class Rook: public Piece {
    public: 
        Rook(bool isWhite);  
        ~Rook();
        char charAt(int row, int col);
        bool isValidMove(int startRow, int startCol, int endRow, int endCol);
};

#endif