#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <tuple>
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

    //all moves INCLUDING ones that kill opposing king
    std::vector<std::tuple<int, int, int, int, bool, bool>> allWhiteMoves;
    std::vector<std::tuple<int, int, int, int, bool, bool>> allBlackMoves;

    //all moves EXCULDING ones that kill opposing king
    //therefore, all legal moves that a player could make
    std::vector<std::tuple<int, int, int, int, bool, bool>> allLegalWhiteMoves;
    std::vector<std::tuple<int, int, int, int, bool, bool>> allLegalBlackMoves;

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
    bool isValidMove(bool isWhitePLayer, int startRow, int startCol, int endRow, int endCol);

    void updateWhiteKingCoordinates(int row, int col);
    void updateBlackKingCoordinates(int row, int col);
    bool isCheck(bool checkingWhiteKing);
    bool isCheckmate(bool checkingWhite);
    bool isStalemate(bool isCheckingWhite);

    //the following functions are for the setup mode
    bool hasOneWhiteKing();
    bool hasOneBlackKing();
    bool hasNoPawnsFirstLastRow();

    static std::pair<int, int> notationToCoordinates(std::string notation);

    //setter functions for all valid moves
    //startRow, startCol, endRow, endCol, isCapture, isCheck
    void generateAllWhiteMoves();
    void generateAllBlackMoves();

    //getter functions for all valid moves
    std::vector<std::tuple<int, int, int, int, bool, bool>> getAllLegalWhiteMoves();
    std::vector<std::tuple<int, int, int, int, bool, bool>> getAllLegalBlackMoves();


};

#endif
