#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include <cmath>
#include "../board.h"
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

bool Queen::isOpponentPiece(Board* board, int endRow, int endCol){
    if (endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0){
        return false;
    }
    if (board->getPiece(endRow, endCol)->isWhite() != this->isWhite() && board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
        return true;
    }
    return false;
}

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> Queen::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> movesQueen;
    std::vector<std::tuple<int, int, int, int, bool, bool>> movesRook;
    std::vector<std::tuple<int, int, int, int, bool, bool>> movesBishop;

    Rook tempRook{isWhitePiece};
    Bishop tempBishop{isWhitePiece};

    movesRook = tempRook.generateAllMoves(board, row, col);
    movesBishop = tempBishop.generateAllMoves(board, row, col);

    for (size_t index = 0; index < movesRook.size(); index++){
        movesQueen.emplace_back(movesRook[index]);
    }
    for (size_t index = 0; index < movesBishop.size(); index++){
        movesQueen.emplace_back(movesBishop[index]);
    }
    return movesQueen;
};

Queen::~Queen(){};
