#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <iostream>

class Bishop: public Piece {
    public: 
        Bishop(bool isWhite);  
        ~Bishop();
        char charAt(int row, int col);
        bool isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer);
};

#endif