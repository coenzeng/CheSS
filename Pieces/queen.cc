#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include <cmath>

Queen::Queen(bool isWhitePiece): Piece(isWhitePiece){};  

char Queen::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'Q';
    } else {
        return 'q';
    }
};
bool Queen::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer){
    // temporary objects only used to check validity of move. The colour does not matter.
    Rook tempRook{isWhitePlayer};
    Bishop tempBishop{isWhitePlayer};

    if (tempRook.isValidMove(board, startRow, startCol, endRow, endCol, isWhitePlayer) || tempBishop.isValidMove(board, startRow, startCol, endRow, endCol, isWhitePlayer)){
        return true;
    }

    return false;
};

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> Queen::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
    return moves;
};

Queen::~Queen(){};