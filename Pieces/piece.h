#ifndef PIECE_H
#define PIECE_H
//#include "board.h"
#include <iostream>

class Board;

class Piece {
    protected: 
        bool isWhitePiece;
    public: 
        Piece(bool isWhitePiece);
        virtual ~Piece();
        bool isWhite();
        virtual char charAt(int row, int col) = 0;
        virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol) = 0;
};

#endif
