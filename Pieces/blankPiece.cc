#include "blankPiece.h"

BlankPiece::BlankPiece(bool isWhitePiece): Piece(isWhitePiece){};  

char BlankPiece::charAt(int row, int col)
{
    return ' ';
};
bool BlankPiece::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer)
{
    return true;
};

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> BlankPiece::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
    return moves;
};

BlankPiece::~BlankPiece(){};