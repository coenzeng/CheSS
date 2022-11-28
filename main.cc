#include <iostream>
#include <vector>
#include "board.h"
#include "View/chessStudio.h"
#include "View/textObserver.h"
#include "View/graphicalObserver.h"
#include "View/observer.h"

//return 0 if black wins 
//return 1 if white wins
bool startGame(std::string player1, std::string player2){

  //make a new board
  std::unique_ptr<Board> board = std::make_unique<Board>();
  board->createStartingBoard();
  ChessStudio studio{board.get()};

  //make new observers 
  std::unique_ptr<Observer> textDisplay = std::make_unique<TextObserver>(&studio);
  //std::unique_ptr<Observer> graphicalDisplay = std::make_unique<GraphicalObserver>(&studio, new Xwindow(10*(BOARD_SIZE), 10*(BOARD_SIZE)));

  std::string command;

  while (std::cin >> command) {
    if (command == "render" ) {
      studio.render();
    } 
  }

  //detach observers
  studio.detach(textDisplay.get());
  //studio.detach(textDisplay);    
  return 0;
}; 

void startSetup(){
  //make a new board
  std::unique_ptr<Board> board = std::make_unique<Board>();
  board->createEmptyBoard();
  ChessStudio studio{board.get()};

  //make new observers 
  std::unique_ptr<Observer> textDisplay = std::make_unique<TextObserver>(&studio);
  //std::unique_ptr<Observer> graphicalDisplay = std::make_unique<GraphicalObserver>(&studio, new Xwindow(10*(BOARD_SIZE), 10*(BOARD_SIZE)));

  std::string command;

  while (std::cin >> command) {
    if (command == "render" ) {
      studio.render();
    } 
  }

  //detach observers
  studio.detach(textDisplay.get());
  //studio.detach(textDisplay);    

}; 



int main () {

  int whiteScore = 0;
  int blackScore = 0;

  std::string command;

  while (std::cin >> command) {
    if (command == "game") {
        std::string player1;
        std::string player2;
        std::cin >> player1 >> player2;

        if (startGame(player1, player2)){
          whiteScore += 1;
        } else {
          blackScore += 1;
        }
    } else if (command == "setup") {
      startSetup();
    }
  }

  std::cout << "Final Score:" << std::endl;
  std::cout << "White:" << whiteScore << std::endl;
  std::cout << "Black:" << blackScore << std::endl;

}
