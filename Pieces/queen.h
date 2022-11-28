#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include <iostream>

class Queen: public Piece {
    public: 
        Queen(bool isWhite);  
        ~Queen();
        char charAt(int row, int col);
        bool isValidMove(int startRow, int startCol, int endRow, int endCol);
};

#endif