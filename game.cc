#include "game.h"

//initialize static variables 
int Game::whiteScore = 0;
int Game::blackScore = 0; 

//constructor initializes all smart pointers
Game::Game(): 
    board{std::make_unique<Board>()}, 
    studio{board.get()}, 
    textDisplay{std::make_unique<TextObserver>(&studio)},
    graphicalWindow{std::make_unique<Xwindow>(30*(BOARD_SIZE), 30*(BOARD_SIZE))},
    graphicalDisplay{std::make_unique<GraphicalObserver>(&studio, graphicalWindow.get())},
    currentPlayer{"white"}
{};

Game::~Game(){
    //detach observers
    studio.detach(textDisplay.get());
    studio.detach(graphicalDisplay.get()); 
};

//this reset function is for wiping out changes made in setup mode
void Game::resetToDefault()
{
    board->createStartingBoard();
    currentPlayer = "white";
};

//this function will enter setup mode, 
//and won't leave until setup mode conditions are satisfied 
void Game::startSetup()
{
    //reset everything in setup mode
    board->createEmptyBoard();
    currentPlayer = "white";

    std::string command;

    while (std::cin >> command) {
        if (command == "render") {
            studio.render();
        } else if (command == "done") {
            //add conditions to leave 
            if (board->hasOneWhiteKing() && board->hasOneBlackKing() && board->hasNoPawnsFirstLastRow()){ //also board-> isCheck()
                return;
            } else {
                std::cout << "Conditions not satisfied to leave setup mode." << std::endl;
            }
        }
        else if (command == "+") { //add a piece
            char pieceSymbol;
            std::string location;
            std::cin >> pieceSymbol >> location;
            std::pair<int, int> coordinates = board->notationToCoordinates(location);

            if (board->isValidCoordinate(coordinates.first, coordinates.second) && isValidSymbol(pieceSymbol)){
                board->setPiece(pieceSymbol, coordinates.first, coordinates.second);
            }
            studio.render();

        } else if (command == "-") { //remove a piece
            std::string location;
            std::cin >> location;
            std::pair<int, int> coordinates = board->notationToCoordinates(location);
            if (board->isValidCoordinate(coordinates.first, coordinates.second)){
                board->unSetPiece(coordinates.first, coordinates.second);
            }
            studio.render();
        } else if (command == "=") { //make it "colour" turn to go next
            std::string colour;
            std::cin >> colour;
            if (colour == "white" || colour == "black"){
                currentPlayer = colour;
            }
        }
    }
};

//this function will play an ENTIRE game from start to finish
void Game::startGame(std::string player1, std::string player2)
{
    //set whitePlayer
    if (player1 == "human"){
        whitePlayer = std::make_unique<Human>(true);
    } else if (player1 == "computer1"){
        whitePlayer = std::make_unique<Computer1>(true);
    } else if (player1 == "computer2"){
        whitePlayer = std::make_unique<Computer2>(true);
    } else if (player1 == "computer3"){
        whitePlayer = std::make_unique<Computer3>(true);
    } 
    
    //set blackPlayer
    if (player2 == "human"){
        blackPlayer = std::make_unique<Human>(false);
    } else if (player2 == "computer1"){
        blackPlayer = std::make_unique<Computer1>(false);
    } else if (player2 == "computer2"){
        blackPlayer = std::make_unique<Computer2>(false);
    } else if (player2 == "computer3"){
        blackPlayer = std::make_unique<Computer3>(false);
    }

    std::string command;

    while (std::cin >> command) {
        if (command == "render" ) {
            studio.render();
        } else if (command == "resign"){
            
            //end the game
            //add 1 to other player's score
            if (currentPlayer == "white"){
                incrementBlackScore();
            } else {
                incrementWhiteScore();
            }
            return;
        } else if (command == "move") {

            //if a move is made, switch the players turn and check win conditions
            if (currentPlayer == "white"){
                if (whitePlayer->makeMove(board.get())){
                    currentPlayer = "black";
                    

                    //check win conditions
                    // if isCheck(false){

                    //     std::cout << "Black is in check." << std::endl; 
                    //     if (isCheckmate(false)){
                    //         incrementWhiteScore();
                    //         std::cout << "Checkmate, white wins." << std::endl;
                    //         return;
                    //     } else if (isStalemate()){
                    //         std::cout << "Stalemate." << std::endl;
                    //         return;
                    //     }
                    // }
                }
            } else {
                if (blackPlayer->makeMove(board.get())){
                    currentPlayer = "white";

                    //check win conditions
                    // if isCheck(true){

                    //     std::cout << "White is in check." << std::endl; 
                    //     if (isCheckmate(true)){
                    //         incrementBlackScore();
                    //         std::cout << "Checkmate, white wins." << std::endl;
                    //         return;
                    //     }
                    // } else if (isStalemate(true)){
                    //         std::cout << "Stalemate." << std::endl;
                    //         return;
                    //     }
                }
            }

            
        }

    }
};

void Game::incrementWhiteScore()
{
    whiteScore++;
};

void Game::incrementBlackScore()
{
    blackScore++;
};

int Game::getWhiteScore()
{
    return whiteScore;
};

int Game::getBlackScore()
{
    return blackScore;
};

//this function is for setup mode 
//check if symbol is in the symbolList
bool Game::isValidSymbol(char symbol){
  std::vector<char> symbolList{'b', 'k', 'n', 'p', 'q', 'r', 'B', 'K', 'N', 'P', 'R'};
  for (size_t i = 0; i < symbolList.size(); i++){
    if (symbolList[i] == symbol){
        return true;
    }
  }
  return false;
}