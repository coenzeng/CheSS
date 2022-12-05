#ifndef KING_H
#define KING_H
#include "piece.h"
#include <iostream>

class King: public Piece {
    public: 
        King(bool isWhite);  
        ~King();
        char charAt(int row, int col);
        bool isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer); // need to remove
        bool isOpponentPiece(Board* board, int endRow, int endCol);
        std::vector<std::tuple<int, int, int, int, bool, bool>> generateAllMoves(Board* board, int row, int col);
};

#endif