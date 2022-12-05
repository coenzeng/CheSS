#include "king.h"
#include "../board.h"
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

bool King::isOpponentPiece(Board* board, int endRow, int endCol){
    // if (endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0){
    //     return false;
    // }
    // if (board->getPiece(endRow, endCol)->isWhite() != this->isWhite() && board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
    //     return true;
    // }
    return false;
}

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> King::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
    std::tuple<int, int, int, int, bool, bool> move;

    // add 8 positions surrounding king if final position is not out of bounds or it does not have a piece of the same colour
    if(isValidPrelim(board, row - 1, col, isWhitePiece)){ // up
        if (isOpponentPiece(board, row - 1, col)){
            move = std::make_tuple(row, col, row - 1, col, true, false);
        } else {
            move = std::make_tuple(row, col, row - 1, col, false, false);
        }
        moves.emplace_back(move);
    }

    if(isValidPrelim(board, row + 1, col, isWhitePiece)){ // down
        if (isOpponentPiece(board, row + 1, col)){
            move = std::make_tuple(row, col, row + 1, col, true, false);
        } else {
            move = std::make_tuple(row, col, row + 1, col, false, false);
        }
        moves.emplace_back(move);
    }

    if(isValidPrelim(board, row, col + 1, isWhitePiece)){ // right
        if (isOpponentPiece(board, row, col + 1)){
            move = std::make_tuple(row, col, row, col + 1, true, false);
        } else {
            move = std::make_tuple(row, col, row , col + 1, false, false);
        }
        moves.emplace_back(move);
    }

    if(isValidPrelim(board, row, col - 1, isWhitePiece)){ // left
        if (isOpponentPiece(board, row, col - 1)){
            move = std::make_tuple(row, col, row, col - 1, true, false);
        } else {
            move = std::make_tuple(row, col, row , col - 1, false, false);
        }
        moves.emplace_back(move);
    }

    if(isValidPrelim(board, row - 1, col - 1, isWhitePiece)){ // up left
        if (isOpponentPiece(board, row - 1, col - 1)){
            move = std::make_tuple(row, col, row - 1, col - 1, true, false);
        } else {
            move = std::make_tuple(row, col, row - 1, col - 1, false, false);
        }
        moves.emplace_back(move);
    }

    if(isValidPrelim(board, row - 1, col + 1, isWhitePiece)){ // up right
        if (isOpponentPiece(board, row - 1, col + 1)){
            move = std::make_tuple(row, col, row - 1, col + 1, true, false);
        } else {
            move = std::make_tuple(row, col, row - 1, col + 1, false, false);
        }
        moves.emplace_back(move);
    }

    if(isValidPrelim(board, row + 1, col - 1, isWhitePiece)){ // down left
        if (isOpponentPiece(board, row + 1, col - 1)){
            move = std::make_tuple(row, col, row + 1, col - 1, true, false);
        } else {
            move = std::make_tuple(row, col, row + 1, col - 1, false, false);
        }
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row + 1, col + 1, isWhitePiece)){ // down right
        if (isOpponentPiece(board, row + 1, col + 1)){
            move = std::make_tuple(row, col, row + 1, col + 1, true, false);
        } else {
            move = std::make_tuple(row, col, row + 1, col + 1, false, false);
        }
        moves.emplace_back(move);
    }

    std::cout<<"All of king's moves: "<<std::endl;
    debugPrintAllMoves(moves);

    return moves;
};

King::~King(){};
