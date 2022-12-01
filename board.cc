#include "board.h"

Board::Board() {
    createEmptyBoard();
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
    return chessBoard[row][col].get();
};

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
    unSetPiece(startRow, startCol); 
    setPiece(charAt(startRow, startCol), endRow, endCol); 
};

bool Board::isValidCoordinate(size_t row, size_t col){
    if (row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE){
        return false;
    };
    return true;
}

//Board::isValidMove()
// check all the conditions that are common for checking every valid move, which include:
//1. Check that starting piece is the players piece
//2. Check boundaries
//3. Check that end piece is NOT the players piece (they can't kill themselves)
//after all these conditions are checked, then check for individual piece moveablity

bool Board::isValidMove(bool isWhitePlayer, size_t startRow, size_t startCol, size_t endRow, size_t endCol)
{
    //check boundaries 
    if (!isValidCoordinate(startRow, startCol) || !isValidCoordinate(endRow, endCol))
    {
        return false;
    };

    //check if no move was made 
    if (startRow == endRow && startCol == endCol)
    {
        return false;
    }

    //check if the start piece is blank
    if (charAt(startRow, startCol) == ' ')
    {
        return false;
    }

    //check if white player turn, but is trying to move black piece
    if (isWhitePlayer && !getPiece(startRow, startCol)->isWhite())
    {
        return false;
    }
    //check if black player turn, but is trying to move white piece
    if (!isWhitePlayer && getPiece(startRow, startCol)->isWhite())
    {
        return false;
    }

    //check if the player is trying to kill themselves
    if (isWhitePlayer == getPiece(endRow, endCol)->isWhite() && charAt(endRow, endCol) != ' ')
    {
        return false;
    } 

    //check if the player is trying to kill a king
    if (charAt(endRow, endCol) == 'K' || charAt(endRow, endCol) == 'k')
    {
        return false;
    }

    return getPiece(startRow, startCol)->isValidMove(this, startRow, startCol, endRow, endCol, isWhitePlayer);

};

// bool Board::anyValidMoves(bool isWhitePlayer, size_t startRow, size_t startCol) {
//     //Any valid Pawn moves?
//         if (charAt(startRow, startCol) == 'p') {
//             {
//                 for (int numSteps = 1; numSteps <= 2; numSteps++) {
//                 if (isValidMove(true, startRow, startCol, endRow + numSteps, startCol)) {
//                     return true;
//                 }
//                 else return false;
//                 }
//             }
//         }
//         if (charAt(startRow, startCol) == 'P') {
//             {
//                 for (int numSteps = 1; numSteps <= 2; numSteps++) {
//                 if (isValidMove(false, startRow, startCol, endRow - numSteps, startCol)) {
//                     return true;
//                 }
//                 else return false;
//                 }
//             }
//         }

//     }

//check if the player is in check
bool Board::isCheck()
{
    return true;
};

bool Board::isCheckmate()
{
    // if(isCheck){
    // //the fn below does not exist yet but anyValidMoves should check for all
    // // possible moves minus all illegal moves for each piece
    //     if(!anyValidMoves){
    //         cout << ("Checkmate") << endl;
    //         return true;
    //     }
    //     return false;
    //     }
    return true;
};

bool Board::isStalemate()
{
    // if(!isCheck){
    // //the fn below does not exist yet but anyValidMoves should check for all
    // // possible moves minus all illegal moves for each piece
    //     if(!anyValidMoves){
    //         cout << ("Stalemate") << endl;
    //         return true;
    //     }
    //     return false;
    //     }
    return true;
};

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