#include "piece.h"

Piece::Piece(bool isWhitePiece): isWhitePiece{isWhitePiece}{};

Piece::~Piece(){};

bool Piece::isWhite()
{
    return isWhitePiece;
};