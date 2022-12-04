#include "computer2.h"

Computer2::Computer2(bool isWhite): isWhite{isWhite} {};
Computer2::~Computer2(){};
bool Computer2::makeMove(Board * board)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;

    if (isWhite){
        moves = board->getAllLegalWhiteMoves();
    } else {
        moves = board->getAllLegalBlackMoves();
    }

    int startRow;
    int startCol;
    int endRow;
    int endCol;

    //search for capture move
    for (size_t index = 0; index < moves.size(); index++){
        if (std::get<4>(moves[index])){ //the 4th index is a boolean for isCapture
            startRow = std::get<0>(moves[index]);
            startCol = std::get<1>(moves[index]);
            endRow = std::get<2>(moves[index]);
            endCol = std::get<3>(moves[index]);
            board->makeMove(startRow, startCol, endRow, endCol);
            return true;
        };
    }
    
    //if there are no capture moves, pick a random legal move 

    int randomIndex = rand() % moves.size(); //generate a random number between [0, moves.size() - 1]
    
    startRow = std::get<0>(moves[randomIndex]);
    startCol = std::get<1>(moves[randomIndex]);
    endRow = std::get<2>(moves[randomIndex]);
    endCol = std::get<3>(moves[randomIndex]);

    board->makeMove(startRow, startCol, endRow, endCol);
    return true;
};