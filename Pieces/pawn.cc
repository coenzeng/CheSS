#include "pawn.h"
#include "../board.h"
#include <cmath>

Pawn::Pawn(bool isWhitePiece): Piece(isWhitePiece){};  

char Pawn::charAt(int row, int col)
{
    if (Piece::isWhite()){
        return 'P';
    } else {
        return 'p';
    }
};

/* Valid move in the following cases:
    1. one move in the forward direction at any point in the game (cannot attack)
    2. two moves or one move on the first move of pawn (cannot attack)
    3. moving forward diagonally 1 step if attacking an opponent piece
    4. pawn en passant (not coded yet)
*/

// return true for all possible valid moves, at the end return false if it goes through none of the if blocks
bool Pawn::isValidMove(Board* board, int startRow, int startCol, int endRow, int endCol, bool isWhitePlayer){

    if(isWhitePlayer){
        // forward diagonal move (valid move #3)
        bool isFwdDiagBy1 = (endRow == startRow - 1) && ((endCol == startCol - 1) || (endCol == startCol + 1));
        if(isFwdDiagBy1 && !(board->getPiece(endRow, endCol)->isWhite())){ 
            return true;
        }
        // pawn en passant (to be coded)

        // no other cases where diagonal moves are allowed
        if ((startCol - endCol) != 0){
            return false;
        }
        // no more attacking either
        if(board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
            return false;
        }
        // one or two advances in the first move (valid move #2)
        if(startRow == 6){ 
            if(endRow == 5 || endRow == 4){
                return true;
            }
        }else{
            // one advance in the forward direction (valid move #1)
            if(endRow == (startRow - 1)){
                return true;
            }
        }

        return false;
    } else {
        bool isFwdDiagBy1 = (endRow == startRow + 1) && ((endCol == startCol - 1) || (endCol == startCol + 1));

        //check that not equal to blankPiece, since all blankPieces are initialized as white
        if(isFwdDiagBy1 && board->getPiece(endRow, endCol)->isWhite() && board->charAt(endRow, endCol) != ' '){ 
            return true;
        }
        // pawn en passant (to be coded)

        if ((startCol - endCol) != 0){
            return false;
        }
        if(board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' '){
            return false;
        }
        if(startRow == 1){ 
            if(endRow == 2 || endRow == 3){
                return true;
            }
        }else{
            if(endRow == (startRow + 1)){
                return true;
            }
        }
        return false;
    }

};

//startRow, startCol, endRow, endCol, isCapture, isCheckOnEnemy
std::vector<std::tuple<int, int, int, int, bool, bool>> Pawn::generateAllMoves(Board* board, int row, int col)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
    return moves;
};

Pawn::~Pawn(){};