#include "bishop.h"
#include "../board.h"
#include <cmath>

using namespace std;

Bishop::Bishop(bool isWhitePiece): Piece(isWhitePiece){};  

char Bishop::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'B';
    } else {
        return 'b';
    }
};
bool Bishop::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    int rowDiff = startRow - endRow; // vertical difference (Y)
    int colDiff = startCol - endCol; // horizontal difference (X)

    // not diagonal
    if (abs(rowDiff) != abs(colDiff)){
        return false;
    }
    int pathLength = abs(rowDiff);

    // check all blocks in board until final location (determine direction)
    int directionX, directionY; 
    directionX = signbit(colDiff) ? 1 : -1; // 1 refers to traversing rightward
    directionY = signbit(rowDiff) ? 1 : -1; // 1 refers to traversing downward

    for(int i = 0; i < pathLength - 1; i++){
        int indX = startCol + directionX; 
        int indY = startRow + directionY;
        if(board->getPiece(indX, indY)->charAt(indX, indY) !=  ' '){
            return false;
        }
    }
    
    return true;
};

bool Bishop::isOpponentPiece(Board* board, int endRow, int endCol){
    if (endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0){
        return false;
    }
    if (board->getPiece(endRow, endCol)->isWhite() != this->isWhite() && board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
        return true;
    }
    return false;
}

bool Bishop::isOwnPiece(Board* board, int endRow, int endCol){
    if (endRow > 7 || endRow < 0 || endCol > 7 || endCol < 0){
        return false;
    }
    if (board->getPiece(endRow, endCol)->isWhite() == this->isWhite() && board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
        return true;
    }
    return false;
}

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> Bishop::generateAllMoves(Board* board, int row, int col)
{
    std::vector<tuple<int, int, int, int, bool, bool>> moves;
    std::tuple<int, int, int, int, bool, bool> move;
    int curCol = 0;
    int curRow = 0;

    // top right diag
    curCol = col + 1;
    curRow = row - 1;
    while(curCol < 8 && curCol >= 0 && curRow >= 0 && curRow < 8){
        // encountering player's own piece
        if (isOwnPiece(board, curRow, curCol)){
            break;
        }
        move = std::make_tuple(row, col, curRow, curCol, false, false);
        moves.emplace_back(move);
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, curRow, curCol)){
            break;
        }
        curCol++;
        curRow--;
    }

    // top left diag
    curCol = col - 1;
    curRow = row - 1;
    while(curCol < 8 && curCol >= 0 && curRow >= 0 && curRow < 8){
        // encountering player's own piece
        if (isOwnPiece(board, curRow, curCol)){
            break;
        }
        move = std::make_tuple(row, col, curRow, curCol, false, false);
        moves.emplace_back(move);
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, curRow, curCol)){
            break;
        }
        curCol--;
        curRow--;
    }

    // bottom left diag
    curCol = col - 1;
    curRow = row + 1;
    while(curCol < 8 && curCol >= 0 && curRow >= 0 && curRow < 8){
        // encountering player's own piece
        if (isOwnPiece(board, curRow, curCol)){
            break;
        }
        move = std::make_tuple(row, col, curRow, curCol, false, false);
        moves.emplace_back(move);
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, curRow, curCol)){
            break;
        }
        curCol--;
        curRow++;
    }

    // bottom right diag
    curCol = col + 1;
    curRow = row + 1;
    while(curCol < 8 && curCol >= 0 && curRow >= 0 && curRow < 8){
        // encountering player's own piece
        if (isOwnPiece(board, curRow, curCol)){
            break;
        }
        move = std::make_tuple(row, col, curRow, curCol, false, false);
        moves.emplace_back(move);
        // encountering opponent's piece (add position and break)
        if (isOpponentPiece(board, curRow, curCol)){
            break;
        }
        curCol++;
        curRow++;
    }
    
    return moves;
};

Bishop::~Bishop(){};
