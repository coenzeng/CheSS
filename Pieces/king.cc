#include "king.h"

King::King(bool isWhitePiece): Piece(isWhitePiece){};  

char King::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'K';
    } else {
        return 'k';
    }
};
bool King::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    // only 1 move in any direction
    if (!(abs(startCol - endCol) <= 1 && abs(startRow - endRow) <= 1)){
        return false;
    }

    return true;
};

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> King::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
    return moves;
};

King::~King(){};