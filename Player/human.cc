#include "human.h"
#include <iostream>
Human::Human(bool isWhite): isWhite{isWhite} {};
Human::~Human(){};
bool Human::makeMove(Board * board)
{
    //read input, which will be chess notation
    std::string startNotation;
    std::string endNotation;

    std::cin >> startNotation >> endNotation;

    //convert notation (e3) to coordinates (row, col)
    //std::cout << "isWhite: " << isWhite << std::endl;
    std::pair<int, int> startCoordinates = board->notationToCoordinates(startNotation);
    std::pair<int, int> endCoordinates = board->notationToCoordinates(endNotation);

    int startRow = startCoordinates.first;
    int startCol = startCoordinates.second;
    int endRow = endCoordinates.first;
    int endCol = endCoordinates.second;
    //std::cout << "Coordinates: " << startRow << startCol << endRow << endCol << std::endl;
    //std::cout << board->isValidMove(isWhite, startRow, startCol, endRow, endCol) << std::endl;

    if (board->isValidMove(isWhite, startRow, startCol, endRow, endCol)){
        //check if move is a pawn promotion
        //if yes, take in extra input 
        
        if (board->isPawnPromotion(startRow, startCol, endRow, endCol)){
            char piece;
            std::cin >> piece;
            //returns a boolean if promotion was successful
            return board->promoteThePawn(piece, startRow, startCol, endRow, endCol);

        } else {
            board->makeMove(startRow, startCol, endRow, endCol);
        }
        return true;
    }
    return false;
};