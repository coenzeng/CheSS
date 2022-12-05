#include "piece.h"
#include "../board.h"

Piece::Piece(bool isWhitePiece): isWhitePiece{isWhitePiece}{};

Piece::~Piece(){};

bool Piece::isWhite()
{
    return isWhitePiece;
};

bool Piece::isValidCoordinates(int row, int col){
    return (row >=0 && row <= 7 && col >= 0 && col <= 7);
}

bool Piece::isValidPrelim(Board* board, int endRow, int endCol, bool isWhitePlayer){
    // check for out of bounds and moving into a your own piece
    if(endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7 || ((board->getPiece(endRow, endCol)->isWhite() == isWhitePlayer) && board->getPiece(endRow, endCol)->charAt(endRow, endCol) != ' ')){
        return false;
    }
    return true;
}

void Piece::debugPrintAllMoves(std::vector<std::tuple<int, int, int, int, bool, bool>> moves){
    for (size_t index = 0; index < moves.size(); index++){
        std::cout<<"start: ("<<std::get<0>(moves[index])<<" , "<<std::get<1>(moves[index])<<") end: ("<<std::get<2>(moves[index])<<" , "<<std::get<3>(moves[index])<<")"<<std::endl;
    }
}
