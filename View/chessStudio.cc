#include "chessStudio.h"
void ChessStudio::render(){
  renderObservers();
};

char ChessStudio::getState(int row, int col) const{
  return theChessBoard->charAt(row, col);
};

ChessStudio::~ChessStudio() {
  //DO NOT DELETE THE POINTER HERE. IT IS A SMART POINTER THAT WILL DELETE ITSELF.
  //delete theChessBoard; 
};
