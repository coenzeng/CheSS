#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "board.h"
#include "View/chessStudio.h"
#include "View/textObserver.h"
#include "View/graphicalObserver.h"
#include "View/observer.h"

std::map<char, int> columnLetterToNumber{ 
  {'a', 0}, {'A', 0}, 
  {'b', 1}, {'B', 1},
  {'c', 2}, {'C', 2},
  {'d', 3}, {'D', 3},
  {'e', 4}, {'E', 4},
  {'f', 5}, {'F', 5},
  {'g', 6}, {'G', 6},
  {'h', 7}, {'H', 7}
};

std::vector<char> symbolList{'b', 'k', 'n', 'p', 'q', 'r', 'B', 'K', 'N', 'P', 'R'};

bool isValidSymbol(char symbol){
  for (size_t i = 0; i < symbolList.size(); i++){
    if (symbolList[i] == symbol){
        return true;
    }
  }
  return false;
}

std::pair<int, int> notationToCoordinates(std::string notation){

  //returns (-1, -1) if notation is not valid 
  //check that the key (notation[0]) is in map before accessing it
  if (notation.length() != 2 || !isalpha(notation[0]) || !isdigit(notation[1]) || !columnLetterToNumber.count(notation[0])){
    return std::make_pair(-1, -1);
  }

  int row = notation[1] - '0' - 1; //subtract one to make it zero-indexed
  int col = columnLetterToNumber[notation[0]];
  return std::make_pair(row, col);;
};

//return 0 if black wins 
//return 1 if white wins
bool startGame(std::string player1, std::string player2){

  //make a new board
  std::unique_ptr<Board> board = std::make_unique<Board>();
  board->createStartingBoard();
  ChessStudio studio{board.get()};

  //make new observers 
  std::unique_ptr<Observer> textDisplay = std::make_unique<TextObserver>(&studio);
  std::unique_ptr<Xwindow> graphicalWindow = std::make_unique<Xwindow>(30*(BOARD_SIZE), 30*(BOARD_SIZE));
  std::unique_ptr<Observer> graphicalDisplay = std::make_unique<GraphicalObserver>(&studio, graphicalWindow.get());

  std::string command;

  while (std::cin >> command) {
    if (command == "render" ) {
      studio.render();
    } else if (command == "resign" ) {
      //add conditions to leave 
      break;
    }
  }

  //detach observers
  studio.detach(textDisplay.get());
  studio.detach(graphicalDisplay.get()); 
  return 0;
}; 

void startSetup(){
  //make a new board
  std::unique_ptr<Board> board = std::make_unique<Board>();
  board->createEmptyBoard();
  ChessStudio studio{board.get()};

  //make new observers 
  std::unique_ptr<Observer> textDisplay = std::make_unique<TextObserver>(&studio);
  std::unique_ptr<Xwindow> graphicalWindow = std::make_unique<Xwindow>(30*(BOARD_SIZE), 30*(BOARD_SIZE));
  std::unique_ptr<Observer> graphicalDisplay = std::make_unique<GraphicalObserver>(&studio, graphicalWindow.get());

  std::string command;

  while (std::cin >> command) {
    if (command == "render") {
      studio.render();
    } else if (command == "done") {
      //add conditions to leave 
      break;
    }
    else if (command == "+") {
      char pieceSymbol;
      std::string location;
      std::cin >> pieceSymbol >> location;
      std::pair<int, int> coordinates = notationToCoordinates(location);
      std::cout << "hi" << std::endl;
      std::cout << coordinates.first << coordinates.second << std::endl;
      if (board->isValidCoordinate(coordinates.first, coordinates.second) && isValidSymbol(pieceSymbol)){
        board->setPiece(pieceSymbol, coordinates.first, coordinates.second);
      }
      studio.render();

    } else if (command == "-") {
      std::string location;
      std::cin >> location;
      std::pair<int, int> coordinates = notationToCoordinates(location);
      if (board->isValidCoordinate(coordinates.first, coordinates.second)){
        board->unSetPiece(coordinates.first, coordinates.second);
      }
      studio.render();

    }
  }

  //detach observers
  studio.detach(textDisplay.get());
  studio.detach(graphicalDisplay.get());
  return;
}; 



int main () {

  int whiteScore = 0;
  int blackScore = 0;

  std::string command;

  //once CONTROL-D is pressed, the while loop ecits 
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
  std::cout << "White: " << whiteScore << std::endl;
  std::cout << "Black: " << blackScore << std::endl;
  return 0;
}
