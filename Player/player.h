#ifndef PLAYER_H
#define PLAYER_H

class Board;

class Player {
    public:
        Player();
        virtual ~Player();
        virtual bool makeMove(Board * board) = 0;
};
#endif