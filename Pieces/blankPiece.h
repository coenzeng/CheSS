#ifndef BLANKPIECE_H
#define BLANKPIECE_H
#include "piece.h"
#include <iostream>

class BlankPiece: public Piece {
    public: 
        BlankPiece(bool isWhite);  
        ~BlankPiece();
        char charAt(int row, int col);
        bool isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer);
};

#endif