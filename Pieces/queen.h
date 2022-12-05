#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include <iostream>

class Queen: public Piece {
    public: 
        Queen(bool isWhite);  
        ~Queen();
        char charAt(int row, int col);
        bool isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer);
        bool isOpponentPiece(Board* board, int endRow, int endCol);
        std::vector<std::tuple<int, int, int, int, bool, bool>> generateAllMoves(Board* board, int row, int col);
};

#endif