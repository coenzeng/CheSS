#ifndef PIECE_H
#define PIECE_H
class Board;
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
        virtual bool isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer) = 0;
};

#endif
