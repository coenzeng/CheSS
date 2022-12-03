#include <iostream>
#include <vector>
#include <string>
#include "game.h"

//check that the input for player is valid 
bool isPlayerValid(std::string player)
{
  if (player == "human" || player == "computer1" || player == "computer2" || player == "computer3"){
    return true;
  }
  return false;
}

//"game" starts a new game. Either the board is the default starting board,
//or it's the board made in setup mode
//"setup" enters setup mode
//"reset" wipes out every change made in setup mode. 
//it resets the default board and makes white starting player.
int main () {

  std::string command;
  
  std::unique_ptr<Game> game = std::make_unique<Game>();

  //press control-D to exit while loop
  while (std::cin >> command) {
    if (command == "game") {
      std::string player1;
      std::string player2;
      std::cin >> player1 >> player2;
      if (isPlayerValid(player1) && isPlayerValid(player2)){
        game->startGame(player1, player2);
      }
    } else if (command == "setup") {
      game->startSetup();
    } else if (command == "reset"){
      game->resetToDefault();
    }
  }
  
  std::cout << "Final Score:" << std::endl;
  std::cout << "White: " << Game::getWhiteScore() << std::endl;
  std::cout << "Black: " << Game::getBlackScore() << std::endl;
  return 0;
}
