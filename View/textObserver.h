#ifndef TEXT_OBSERVER_H
#define TEXT_OBSERVER_H
#include <iostream>
//#include "board.h"
#include "observer.h"
//const size_t BOARD_SIZE = 8;

class TextObserver : public Observer {
  ChessStudio* studio;
  std::ostream &out = std::cout;
public:
  TextObserver(ChessStudio* studio);
  void render() override;
};

#endif
