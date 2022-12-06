#ifndef COMPUTER1_H
#define COMPUTER1_H

#include "player.h"
#include "../board.h"

class Computer1: public Player {
    private:
        bool isWhite;
    public:
        Computer1(bool isWhite);
        ~Computer1();
        bool makeMove(Board * board);
};
#endif
