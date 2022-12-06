#include "board.h"

std::map<char, int> Board::columnLetterToNumber{ 
  {'a', 0}, {'A', 0}, 
  {'b', 1}, {'B', 1},
  {'c', 2}, {'C', 2},
  {'d', 3}, {'D', 3},
  {'e', 4}, {'E', 4},
  {'f', 5}, {'F', 5},
  {'g', 6}, {'G', 6},
  {'h', 7}, {'H', 7}
};

Board::Board()
{
    createStartingBoard();
};

Board::~Board(){

};

void Board::createStartingBoard()
{
    if (chessBoard.size() != 0){
        chessBoard.clear();      
    }

    //row 0
    chessBoard.push_back(std::vector <std::unique_ptr<Piece>>());
    chessBoard[0].push_back(std::make_unique<Rook>(false));
    chessBoard[0].push_back(std::make_unique<Knight>(false));
    chessBoard[0].push_back(std::make_unique<Bishop>(false));
    chessBoard[0].push_back(std::make_unique<Queen>(false));
    chessBoard[0].push_back(std::make_unique<King>(false));
    chessBoard[0].push_back(std::make_unique<Bishop>(false));
    chessBoard[0].push_back(std::make_unique<Knight>(false));
    chessBoard[0].push_back(std::make_unique<Rook>(false));

    //row 1
    chessBoard.push_back(std::vector <std::unique_ptr<Piece>>());
    for (size_t j = 0; j < BOARD_SIZE; j++){
        chessBoard[1].push_back(std::make_unique<Pawn>(false));
    }

    //initalize blankPieces
    for (size_t i = 2; i < 6; i++){
        chessBoard.push_back(std::vector <std::unique_ptr<Piece>>());
        for (size_t j = 0; j < BOARD_SIZE; j++){
            chessBoard[i].push_back(std::make_unique<BlankPiece>(true));
        }
    }

    //row 6
    chessBoard.push_back(std::vector <std::unique_ptr<Piece>>());
    for (size_t j = 0; j < BOARD_SIZE; j++){
        chessBoard[6].push_back(std::make_unique<Pawn>(true));
    }

    //row 7
    chessBoard.push_back(std::vector <std::unique_ptr<Piece>>());
    chessBoard[7].push_back(std::make_unique<Rook>(true));
    chessBoard[7].push_back(std::make_unique<Knight>(true));
    chessBoard[7].push_back(std::make_unique<Bishop>(true));
    chessBoard[7].push_back(std::make_unique<Queen>(true));
    chessBoard[7].push_back(std::make_unique<King>(true));
    chessBoard[7].push_back(std::make_unique<Bishop>(true));
    chessBoard[7].push_back(std::make_unique<Knight>(true));
    chessBoard[7].push_back(std::make_unique<Rook>(true));

    previousMove = std::make_tuple(0, 0, 0, 0, false, false);
    isEnPassant = false;
};

void Board::createEmptyBoard()
{
    if (chessBoard.size() != 0){
        chessBoard.clear();      
    }

    for (size_t i = 0; i < BOARD_SIZE; i++){
        chessBoard.push_back(std::vector <std::unique_ptr<Piece>>());
        for (size_t j = 0; j < BOARD_SIZE; j++){
            chessBoard[i].push_back(std::make_unique<BlankPiece>(true));
        }
    }
};

//returns a RAW pointer. 
//why? You should always use a raw pointer if you're not modifying ownership.
Piece* Board::getPiece(int row, int col)
{
    if(row >= 0 && row <= 7 && col >= 0 && col <= 7){
        return chessBoard[row][col].get();
    }else{
        return nullptr;
    }
    
};

//returns the symbol at (row, col)
char Board::charAt(int row, int col)
{
    return getPiece(row, col)->charAt(row, col);
};

void Board::setPiece(char pieceSymbol, int row, int col)
{
    switch(pieceSymbol) {
        case 'b':
            chessBoard[row][col] = std::make_unique<Bishop>(false); 
            break;
        case 'B':
            chessBoard[row][col] = std::make_unique<Bishop>(true); 
            break;
        case 'k':
            chessBoard[row][col] = std::make_unique<King>(false); 
            break;
        case 'K':
            chessBoard[row][col] = std::make_unique<King>(true); 
            break;
        case 'n':
            chessBoard[row][col] = std::make_unique<Knight>(false); 
            break;
        case 'N':
            chessBoard[row][col] = std::make_unique<Knight>(true); 
            break;
        case 'p':
            chessBoard[row][col] = std::make_unique<Pawn>(false); 
            break;
        case 'P':
            chessBoard[row][col] = std::make_unique<Pawn>(true); 
            break;
        case 'q':
            chessBoard[row][col] = std::make_unique<Queen>(false); 
            break;
        case 'Q':
            chessBoard[row][col] = std::make_unique<Queen>(true); 
            break;
        case 'r':
            chessBoard[row][col] = std::make_unique<Rook>(false); 
            break;
        case 'R':
            chessBoard[row][col] = std::make_unique<Rook>(true); 
            break;
        case ' ':
            chessBoard[row][col] = std::make_unique<BlankPiece>(true); 
            break;
        default:
            break;
    }
    return;
};

void Board::unSetPiece(int row, int col)
{
    chessBoard[row][col] = std::make_unique<BlankPiece>(true);
    return;
};

void Board::makeMove(int startRow, int startCol, int endRow, int endCol)
{
    std::cout<<"Given move: (startRow, startCol) to (endRow, endCol)"<<std::endl;
    std::cout << "("<<startRow<<", "<<startCol<<") to ("<<endRow<<", "<<endCol<<")"<<std::endl;

    int prevStartRow = std::get<0>(this->previousMove);
    int prevStartCol = std::get<1>(this->previousMove);
    int prevEndRow = std::get<2>(this->previousMove);
    int prevEndCol = std::get<3>(this->previousMove);

    if(isEnPassant){
        // check if the player used the en passant move
        if(getPiece(startRow, startCol)->charAt(startRow, startCol) == 'p'){ // if player is black
            if (charAt(endRow, endCol) == ' ' && abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1){
                std::cout<<"second insdie if staement"<<std::endl;
                unSetPiece(endRow - 1, endCol);
            }
        }else if(getPiece(startRow, startCol)->charAt(startRow, startCol) == 'P'){ // if player is white
            if (charAt(endRow, endCol) == ' ' && abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1){
                std::cout<<"2 second insdie if statement"<<std::endl;
                unSetPiece(endRow + 1, endCol);
            }
        }
    }
    setPiece(charAt(startRow, startCol), endRow, endCol); 
    unSetPiece(startRow, startCol);

    previousMove = std::make_tuple(startRow, startCol, endRow, endCol, false, false);
    isEnPassant = false; // new turn, EnPassant has to be initialized to false
};

bool Board::isValidCoordinate(size_t row, size_t col){
    if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE){
        return false;
    };
    return true;
}

bool Board::willPutCurrentPlayerInCheck(bool isWhitePlayer, int startRow, int startCol, int endRow, int endCol){

    //remember the current configuration of the board 
    char startPieceSymbol = charAt(startRow, startCol);
    char endPieceSymbol = charAt(endRow, endCol);

    //make a temporary move to see if the current player gets into check
    setPiece(startPieceSymbol, endRow, endCol); 
    unSetPiece(startRow, startCol);

    //generate all moves of the opposing player
    if (isWhitePlayer){
        generateAllBlackMoves(false);
    } else {
        generateAllWhiteMoves(false);
    }

    //UNDO the move
    if (isCheck(isWhitePlayer)){
        setPiece(startPieceSymbol, startRow, startCol);
        setPiece(endPieceSymbol, endRow, endCol);
        return true;
    }
    setPiece(startPieceSymbol, startRow, startCol);
    setPiece(endPieceSymbol, endRow, endCol);
    return false;
}
//check that the move is in the movelist of all possible moves 
//except that a player may NOT kill an opposing king
bool Board::isValidMove(bool isWhitePlayer, int startRow, int startCol, int endRow, int endCol)
{

    if (isWhitePlayer){
        for (size_t index = 0; index < allWhiteMoves.size(); index++){
            int tempStartRow = std::get<0>(allWhiteMoves[index]);
            int tempStartCol = std::get<1>(allWhiteMoves[index]);
            int tempEndRow = std::get<2>(allWhiteMoves[index]);
            int tempEndCol = std::get<3>(allWhiteMoves[index]);
            
            if (startRow == tempStartRow && startCol == tempStartCol && endRow == tempEndRow && endCol == tempEndCol && charAt(endRow, endCol) != 'k'){
                return true;
            }
        }
    } else {
        for (size_t index = 0; index < allBlackMoves.size(); index++){
            int tempStartRow = std::get<0>(allBlackMoves[index]);
            int tempStartCol = std::get<1>(allBlackMoves[index]);
            int tempEndRow = std::get<2>(allBlackMoves[index]);
            int tempEndCol = std::get<3>(allBlackMoves[index]);
            
            if (startRow == tempStartRow && startCol == tempStartCol && endRow == tempEndRow && endCol == tempEndCol && charAt(endRow, endCol) != 'K'){
                return true;
            }
        } 
    }
    //if the move is not in the movelist, return false
    return false;

};

//check if the player is in check
bool Board::isCheck(bool checkingWhiteKing)
{
    //if the lengths are not equal, then "allBlackMoves" has one or more moves that could kill the king
    //therefore white is in check
    if (checkingWhiteKing){
        
        return allBlackMoves.size() != allLegalBlackMoves.size();
    } else {
        return allWhiteMoves.size() != allLegalWhiteMoves.size();
    }
    //OLD CODE:
    // if (checkingWhiteKing){
    //     for (size_t index = 0; index < allBlackMoves.size(); index++){
    //         int endRow = std::get<2>(allBlackMoves[index]);
    //         int endCol = std::get<3>(allBlackMoves[index]);
            
    //         //if the king is under attack, return true
    //         if (charAt(endRow, endCol) == 'K'){
    //             return true;
    //         }
    //     }
    //     return false;

    // } else if (!checkingWhiteKing){
    //     for (size_t index = 0; index < allWhiteMoves.size(); index++){
    //         int endRow = std::get<2>(allWhiteMoves[index]);
    //         int endCol = std::get<3>(allWhiteMoves[index]);
            
    //         //if the king is under attack, return true
    //         if (charAt(endRow, endCol) == 'k'){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};


//first ensure that the king is currently in check, which is done in game.cc
//now the current player will try to perform every single legal move to get it out of check
//if they can't make any legal moves that get it out of check,
//it's a checkmate
bool Board::isCheckmate(bool checkingWhite)
{
    if (checkingWhite){
        generateAllWhiteMoves(true);
        for (size_t index = 0; index < allLegalWhiteMoves.size(); index++){
            int startRow = std::get<0>(allLegalWhiteMoves[index]);
            int startCol = std::get<1>(allLegalWhiteMoves[index]);
            int endRow = std::get<2>(allLegalWhiteMoves[index]);
            int endCol = std::get<3>(allLegalWhiteMoves[index]);
            if (!willPutCurrentPlayerInCheck(checkingWhite, startRow, startCol, endRow, endCol)){
                return false;
            }
        }
    } else {
        generateAllBlackMoves(true);
        for (size_t index = 0; index < allLegalBlackMoves.size(); index++){
            int startRow = std::get<0>(allLegalBlackMoves[index]);
            int startCol = std::get<1>(allLegalBlackMoves[index]);
            int endRow = std::get<2>(allLegalBlackMoves[index]);
            int endCol = std::get<3>(allLegalBlackMoves[index]);
            if (!willPutCurrentPlayerInCheck(checkingWhite, startRow, startCol, endRow, endCol)){
                return false;
            }
        }
    }
    return true;
};

//first ensure that the king is currently NOT in check, which is done in game.cc
//if they have no legal moves, it's a stalemate
bool Board::isStalemate(bool checkingWhite)
{
    if (checkingWhite){
        generateAllWhiteMoves(true);
        for (size_t index = 0; index < allLegalWhiteMoves.size(); index++){
            int startRow = std::get<0>(allLegalWhiteMoves[index]);
            int startCol = std::get<1>(allLegalWhiteMoves[index]);
            int endRow = std::get<2>(allLegalWhiteMoves[index]);
            int endCol = std::get<3>(allLegalWhiteMoves[index]);
            if (!willPutCurrentPlayerInCheck(checkingWhite, startRow, startCol, endRow, endCol)){
                return false;
            }
        }
    } else {
        generateAllBlackMoves(true);
        for (size_t index = 0; index < allLegalBlackMoves.size(); index++){
            int startRow = std::get<0>(allLegalBlackMoves[index]);
            int startCol = std::get<1>(allLegalBlackMoves[index]);
            int endRow = std::get<2>(allLegalBlackMoves[index]);
            int endCol = std::get<3>(allLegalBlackMoves[index]);
            if (!willPutCurrentPlayerInCheck(checkingWhite, startRow, startCol, endRow, endCol)){
                return false;
            }
        }
    }
    return true;
};


//for setup mode
bool Board::hasOneWhiteKing()
{
    int whiteKingCount = 0;
    for (size_t i = 0; i < BOARD_SIZE; i++){
        for (size_t j = 0; j < BOARD_SIZE; j++){
            if (charAt(i, j) == 'K'){
                whiteKingCount += 1;
            }
        }
    }
    return whiteKingCount == 1;
};

//for setup mode
bool Board::hasOneBlackKing()
{
    int blackKingCount = 0;
    for (size_t i = 0; i < BOARD_SIZE; i++){
        for (size_t j = 0; j < BOARD_SIZE; j++){
            if (charAt(i, j) == 'k'){
                blackKingCount += 1;
            }
        }
    }
    return blackKingCount == 1;
};

//for setup mode
bool Board::hasNoPawnsFirstLastRow()
{
    for (size_t j = 0; j < BOARD_SIZE; j++){
       if (charAt(0, j) == 'P') return false;
       if (charAt(0, j) == 'p') return false;
       if (charAt(BOARD_SIZE - 1, j) == 'P') return false;
       if (charAt(BOARD_SIZE - 1, j) == 'p') return false;
    }
    return true;
};

//this function converts position notation (like e3) to coordinates 
std::pair<int, int> Board::notationToCoordinates(std::string notation){

  //returns (-1, -1) if notation is not valid 
  //check that the key (notation[0]) is in map before accessing it
  if (notation.length() != 2 || !isalpha(notation[0]) || !isdigit(notation[1]) || !columnLetterToNumber.count(notation[0])){
    return std::make_pair(-1, -1);
  }

  int row = BOARD_SIZE - (notation[1] - '0'); //do BOARD_SIZE - input since row is reversed
  int col = columnLetterToNumber[notation[0]];
  return std::make_pair(row, col);;
};

//populates "allWhiteMoves" and "allLegalWhiteMoves"
//including moves that capture the enemy King

void Board::generateAllWhiteMoves(bool isFirstCall)
{
    //create new vector 
    if (!allWhiteMoves.empty()){
        allWhiteMoves.clear();
    }

    if (!allLegalWhiteMoves.empty()){
        allLegalWhiteMoves.clear();
    }

    for (size_t row = 0; row < BOARD_SIZE; row++){
        for (size_t col = 0; col < BOARD_SIZE; col++){
            if (getPiece(row, col)->isWhite() && charAt(row, col) != ' '){ 
                //if the piece is white and not blank
                //get the list of moves for the current piece
                std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
                moves = getPiece(row, col)->generateAllMoves(this, row, col);
                //append this list to the list of allWhiteMoves
                for (size_t index = 0; index < moves.size(); index++){
                    
                    int startRow = std::get<0>(moves[index]);
                    int startCol = std::get<1>(moves[index]);
                    int endRow = std::get<2>(moves[index]);
                    int endCol = std::get<3>(moves[index]);
                    //SKIP this move if puts current player in check
                    //Only check this condition on the first call
                    //or else infinite recursion happens
                    if (isFirstCall){
                        if (willPutCurrentPlayerInCheck(true, startRow, startCol, endRow, endCol)){
                            continue;
                        }
                    }
        
                    allWhiteMoves.emplace_back(moves[index]);
                    
                    //killing a king is not legal
                    if (charAt(endRow, endCol) != 'k'){
                        allLegalWhiteMoves.emplace_back(moves[index]);
                    }
                }
            }
        }
    }
    return;
};

//populates "allBlackMoves" with a list of all legal black moves
//including moves that capture the enemy King
void Board::generateAllBlackMoves(bool isFirstCall)
{
    //create new vector 
    if(!allBlackMoves.empty()){
        allBlackMoves.clear();
    }

    if(!allLegalBlackMoves.empty()){
        allLegalBlackMoves.clear();
    }

    for (size_t row = 0; row < BOARD_SIZE; row++){
        for (size_t col = 0; col < BOARD_SIZE; col++){
            if (!getPiece(row, col)->isWhite()){ 
                //if the piece is black
                //get the list of moves for the current piece
                std::vector<std::tuple<int, int, int, int, bool, bool>> moves;
                moves = getPiece(row, col)->generateAllMoves(this, row, col);
                
                //append this list to the list of all Black Moves
                for (size_t index = 0; index < moves.size(); index++){
                    
                    int startRow = std::get<0>(moves[index]);
                    int startCol = std::get<1>(moves[index]);
                    int endRow = std::get<2>(moves[index]);
                    int endCol = std::get<3>(moves[index]);

                    //SKIP this move if puts current player in check
                    //Only check this condition on the first call
                    //or else infinite recursion happens
                    if (isFirstCall){
                        if (willPutCurrentPlayerInCheck(false, startRow, startCol, endRow, endCol)){
                            continue;
                        }
                    }

                    allBlackMoves.emplace_back(moves[index]);
                    //killing a king is not legal
                    if (charAt(endRow, endCol) != 'K'){
                        allLegalBlackMoves.emplace_back(moves[index]);
                    }
                }
            }
        }
    }

    return;
};

//tuple< int startRow, int startCol, int endRow, int endCol, bool isCapture, bool isCheck>
std::vector<std::tuple<int, int, int, int, bool, bool>> Board::getAllLegalWhiteMoves(){
    return allLegalWhiteMoves;
};

//tuple< int startRow, int startCol, int endRow, int endCol, bool isCapture, bool isCheck>
std::vector<std::tuple<int, int, int, int, bool, bool>> Board::getAllLegalBlackMoves(){
    return allLegalBlackMoves;
}

bool Board::isPawnPromotion(int startRow, int startCol, int endRow, int endCol){
    //check if promote white Pawn
    //endRow == 0 means top row of the board
    if (charAt(startRow, startCol) == 'P' && endRow == 0){
        return true;

    //check if promote black pawn 
    //endRow == BOARD_SIZE means bottom row of the board
    } else if (charAt(startRow, startCol) == 'p' && endRow == (BOARD_SIZE - 1)){
        return true;
    }
    return false;
}

bool Board::promoteThePawn(char symbol, int startRow, int startCol, int endRow, int endCol)
{
    //promoting a WHITE pawn
    if (charAt(startRow, startCol) == 'P' && (symbol == 'Q' || symbol == 'R' || symbol == 'B' || symbol == 'N')){
        unSetPiece(startRow, startCol);
        setPiece(symbol, endRow, endCol);
        return true;
    
    //promoting a BLACK pawn
    } else if (charAt(startRow, startCol) == 'p' && (symbol == 'q' || symbol == 'r' || symbol == 'b' || symbol == 'n')){
        unSetPiece(startRow, startCol);
        setPiece(symbol, endRow, endCol);
        return true;
    }

    //if the symbol is not valid, return false
    return false;
};
