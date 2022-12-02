#ifndef COMPUTER3_H
#define COMPUTER3_H

#include "player.h"
#include "../board.h"

class Computer3: public Player {
    private:
        bool isWhite;
    public:
        Computer3(bool isWhite);
        ~Computer3();
        bool makeMove(Board * board);
};
#endif