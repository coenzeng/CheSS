#ifndef CHESS_STUDIO_H
#define CHESS_STUDIO_H
#include <iostream>
#include "subject.h"

class Board;

class ChessStudio: public Subject {
  Board *theChessBoard;

 public:
  explicit ChessStudio(Board *theChessBoard): theChessBoard{theChessBoard} {}

  Board *&chessBoard() { return theChessBoard; }
  void render();
  char getState(int row, int col) const;
  ~ChessStudio();
};

#endif
