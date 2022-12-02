#include "computer1.h"
#include <iostream>
Computer1::Computer1(bool isWhite): isWhite{isWhite} {};
Computer1::~Computer1(){};
bool Computer1::makeMove(Board * board)
{
    std::cout << "I am a computer bruh" << std::endl;
    return true;
};