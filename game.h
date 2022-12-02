#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm> 
#include <map>

#include "board.h"

#include "View/chessStudio.h"
#include "View/textObserver.h"
#include "View/graphicalObserver.h"
#include "View/observer.h"

#include "Player/player.h"
#include "Player/human.h"
#include "Player/computer1.h"
#include "Player/computer2.h"
#include "Player/computer3.h"

class Game {
  private:
    //non-static members that are unique to each game
    std::unique_ptr<Board> board;
    ChessStudio studio;
    std::unique_ptr<Observer> textDisplay;
    std::unique_ptr<Xwindow> graphicalWindow;
    std::unique_ptr<Observer> graphicalDisplay;
    std::unique_ptr<Player> whitePlayer;
    std::unique_ptr<Player> blackPlayer;
    std::string currentPlayer; 

    //static members that is true for every game 
    static int whiteScore;
    static int blackScore;
  
  public:
    Game();
    ~Game();

    void setWhitePlayer(std::string player);
    void setBlackPlayer(std::string player);
    void resetToDefault();
    void startSetup();
    void startGame(std::string player1, std::string player2);
    static void incrementWhiteScore();
    static void incrementBlackScore();
    static int getWhiteScore();
    static int getBlackScore();
    bool isValidSymbol(char symbol);
};

#endif
