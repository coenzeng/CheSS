#include "rook.h"
#include "../board.h"
#include <cmath>
using namespace std;

Rook::Rook(bool isWhitePiece): Piece(isWhitePiece){};  

char Rook::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'R';
    } else {
        return 'r';
    }
};

bool Rook::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    // only vertical or horizontal moves allowed
    if (!(startRow == endRow || startCol == endCol)){
        return false;
    }
    int directionX, directionY; 
    directionX = signbit(startCol - endCol) ? 1 : -1; // 1 refers to traversing rightward
    directionY = signbit(startRow - endRow) ? 1 : -1; // 1 refers to tranversing downward
    
    if (startRow - endRow == 0){
        directionY = 0; // moving horizontally
    }else{
        directionX = 0; // moving vertically
    }
    int pathLength = 0;

    pathLength = max(abs(startCol - endCol), abs(startRow - endRow));
    
    // Either directionX or directionY is 0, and the other is -1 or 1
    for(int i = 0; i < pathLength - 1; i++){
        int indX = startCol + directionX; // one of them will stay constant
        int indY = startRow + directionY;
        if(board->getPiece(indY, indX)->charAt(indY, indX) !=  ' '){
            return false;
        }
    }

    return true;
};

bool Rook::isOpponentPiece(Board* board, int endRow, int endCol){
    if (endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0){
        return false;
    }
    if (board->getPiece(endRow, endCol)->isWhite() != this->isWhite() && board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
        return true; // opponent piece
    }
    return false; // could be your own piece, or a blank piece 
}

bool Rook::isOwnPiece(Board* board, int endRow, int endCol){
    if (endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0){
        return false;
    }
    if (board->getPiece(endRow, endCol)->isWhite() == this->isWhite() && board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
        return true; // your own piece
    }
    return false; // opponent's or blank piece
}

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> Rook::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
    std::tuple<int, int, int, int, bool, bool> move;
    // up
    for(int i = row - 1; i >= 0; i--){
        // encountering player's own piece
        if (isOwnPiece(board, i, col)){
            break;
        }
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, row, i)){
            move = std::make_tuple(row, col, row, i, true, false);
            moves.emplace_back(move);
            break;
        } else {
            move = std::make_tuple(row, col, row, i, false, false);
            moves.emplace_back(move);
        }
    }

    // down
    for(int i = row + 1; i < 8; i++){
        // encountering player's own piece
        if (isOwnPiece(board, i, col)){
            break;
        }
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, row, i)){
            move = std::make_tuple(row, col, row, i, true, false);
            moves.emplace_back(move);
            break;
        } else {
            move = std::make_tuple(row, col, row, i, false, false);
            moves.emplace_back(move);
        }
    }

    // left
    for(int i = col - 1; i >= 0; i--){
        // encountering player's own piece
        if (isOwnPiece(board, row, i)){
            break;
        }
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, row, i)){
            move = std::make_tuple(row, col, row, i, true, false);
            moves.emplace_back(move);
            break;
        } else {
            move = std::make_tuple(row, col, row, i, false, false);
            moves.emplace_back(move);
        }
    }

    // right
    for(int i = col + 1; i <= 7; i++){
        // encountering player's own piece
        if (isOwnPiece(board, row, i)){
            break;
        }
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, row, i)){
            move = std::make_tuple(row, col, row, i, true, false);
            moves.emplace_back(move);
            break;
        } else {
            move = std::make_tuple(row, col, row, i, false, false);
            moves.emplace_back(move);
        }
    }
    
    return moves;
};

Rook::~Rook(){};
