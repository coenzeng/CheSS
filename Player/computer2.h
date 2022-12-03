#ifndef COMPUTER2_H
#define COMPUTER2_H

#include "player.h"
#include "../board.h"

class Computer2: public Player {
    private:
        bool isWhite;
    public:
        Computer2(bool isWhite);
        ~Computer2();
        bool makeMove(Board * board);
};
#endif