#include "computer1.h"
#include <iostream>
Computer1::Computer1(bool isWhite): isWhite{isWhite} {};
Computer1::~Computer1(){};
bool Computer1::makeMove(Board * board)
{
    std::vector<std::tuple<int, int, int, int, bool, bool>> moves;

    if (isWhite){
        moves = board->getAllLegalWhiteMoves();
    } else {
        moves = board->getAllLegalBlackMoves();
    }

    //it is never possible for a player to start with no legal moves
    //therefore, this possibility does NOT need to be checked
    // if (moves.empty()){
    //     return false;
    // }

    int randomIndex = rand() % moves.size(); //generate a random number between [0, moves.size() - 1]
    
    int startRow = std::get<0>(moves[randomIndex]);
    int startCol = std::get<1>(moves[randomIndex]);
    int endRow = std::get<2>(moves[randomIndex]);
    int endCol = std::get<3>(moves[randomIndex]);

    board->makeMove(startRow, startCol, endRow, endCol);
    return true;
};