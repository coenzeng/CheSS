#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include "../board.h"

class Human: public Player {
    private:
        bool isWhite;
    public:
        Human(bool isWhite);
        ~Human();
        bool makeMove(Board * board);
};

#endif