#include "knight.h"
#include <cmath>

Knight::Knight(bool isWhitePiece): Piece(isWhitePiece){};  

char Knight::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'N';
    } else {
        return 'n';
    }
};
bool Knight::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    // knight can leap over other pieces, so do not need to check if path is empty
    if(((abs(startRow - endRow) == 1) && (abs(startCol - endCol) == 2)) ||
       ((abs(startRow - endRow) == 2) && (abs(startCol - endCol) == 1))){
        return true;
       }
    return false;
};

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> Knight::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
    std::tuple<int, int, int, int, bool, bool> move;

    // add 8 positions of knight if final position is not out of bounds or it does not have a piece of the same colour
    if(isValidPrelim(board, row + 1, col + 2, isWhitePiece)){
        move = std::make_tuple(row, col, row + 1, col + 2, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row + 2, col + 1, isWhitePiece)){
        move = std::make_tuple(row, col, row + 2, col + 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row + 2, col - 1, isWhitePiece)){
        move = std::make_tuple(row, col, row + 2, col - 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row + 1, col - 2, isWhitePiece)){
        move = std::make_tuple(row, col, row + 1, col - 2, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row - 1, col - 2, isWhitePiece)){
        move = std::make_tuple(row, col, row - 1, col - 2, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row - 2, col - 1, isWhitePiece)){
        move = std::make_tuple(row, col, row - 2, col - 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row - 2, col + 1, isWhitePiece)){
        move = std::make_tuple(row, col, row - 2, col + 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row - 1, col + 2, isWhitePiece)){
        move = std::make_tuple(row, col, row - 1, col + 2, false, false);
        moves.emplace_back(move);

    }
    std::cout<<"All of knight's moves: "<<std::endl;
    debugPrintAllMoves(moves);

    return moves;
};

Knight::~Knight(){};
