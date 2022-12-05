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
    std::tuple<int, int, int, int, bool, bool> move;

    // add 8 positions surrounding king if final position is not out of bounds or it does not have a piece of the same colour
    if(isValidPrelim(board, row - 1, col, isWhitePiece)){ // up
        move = std::make_tuple(row, col, row - 1, col, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row + 1, col, isWhitePiece)){ // down
        move = std::make_tuple(row, col, row + 1, col, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row, col + 1, isWhitePiece)){ // right
        move = std::make_tuple(row, col, row, col + 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row, col - 1, isWhitePiece)){ // left
        move = std::make_tuple(row, col, row, col - 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row - 1, col - 1, isWhitePiece)){ // up left
        move = std::make_tuple(row, col, row - 1, col - 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row - 1, col + 1, isWhitePiece)){ // up right
        move = std::make_tuple(row, col, row - 1, col + 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row + 1, col - 1, isWhitePiece)){ // down left
        move = std::make_tuple(row, col, row + 1, col - 1, false, false);
        moves.emplace_back(move);

    }
    if(isValidPrelim(board, row + 1, col + 1, isWhitePiece)){ // down right
        move = std::make_tuple(row, col, row + 1, col + 1, false, false);
        moves.emplace_back(move);

    }

    std::cout<<"All of king's moves: "<<std::endl;
    debugPrintAllMoves(moves);

    return moves;
};

King::~King(){};
