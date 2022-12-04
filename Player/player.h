#ifndef PLAYER_H
#define PLAYER_H
#include <stdlib.h> //rand()
class Board;

class Player {
    public:
        Player();
        virtual ~Player();
        virtual bool makeMove(Board * board) = 0;
};
#endif