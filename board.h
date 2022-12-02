#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <algorithm> 
#include "Pieces/piece.h"
#include "Pieces/bishop.h"
#include "Pieces/blankPiece.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"

const size_t BOARD_SIZE = 8;

class Board {
  private: 
    std::vector<std::vector<std::unique_ptr<Piece>>> chessBoard;
    static std::map<char, int> columnLetterToNumber;

  public:
    Board();
    ~Board();
    Piece* getPiece(int row, int col);
    char charAt(int row, int col);
    void createStartingBoard();
    void createEmptyBoard();
    void setPiece(char pieceSymbol, int row, int col); 
    void unSetPiece(int row, int col); 
    void makeMove(int startRow, int startCol, int endRow, int endCol);
    bool isValidCoordinate(size_t row, size_t col);
    bool isValidMove(bool isWhitePLayer, size_t startRow, size_t startCol, size_t endRow, size_t endCol);
    bool isCheck();
    bool isCheckmate();
    bool isStalemate();

    //the following functions are for the setup mode
    bool hasOneWhiteKing();
    bool hasOneBlackKing();
    bool hasNoPawnsFirstLastRow();

    static std::pair<int, int> notationToCoordinates(std::string notation);

};

#endif
