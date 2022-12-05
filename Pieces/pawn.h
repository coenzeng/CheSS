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
        bool isOpponentPiece(Board* board, int row, int col);
        std::vector<std::tuple<int, int, int, int, bool, bool>> generateAllMoves(Board* board, int row, int col);
};

#endif