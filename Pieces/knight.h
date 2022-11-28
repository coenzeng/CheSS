#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include <iostream>

class Knight: public Piece {
    public: 
        Knight(bool isWhite);  
        ~Knight();
        char charAt(int row, int col);
        bool isValidMove(int startRow, int startCol, int endRow, int endCol);
};

#endif