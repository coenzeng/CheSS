#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include <iostream>

class Knight: public Piece {
    public: 
        Knight(bool isWhite);  
        ~Knight();
        char charAt(int row, int col);
        bool isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer);
};

#endif