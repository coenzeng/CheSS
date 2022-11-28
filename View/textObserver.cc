#include "textObserver.h"

TextObserver::TextObserver(ChessStudio* studio): studio{studio}
{
    studio->attach(this);
};

void TextObserver::render() {
    out << '+';
    for (size_t j = 0; j < BOARD_SIZE; j++) out << '-';
    out << '+' << std::endl;
    for (size_t i = 0; i < BOARD_SIZE; i ++) {
        out << '|';
        for (size_t j = 0; j < BOARD_SIZE; j++) {
        out << studio->getState(i, j);
        }
        out << '|' << std::endl;
    }
    out << '+';
    for (size_t j = 0; j < BOARD_SIZE; j++) out << '-';
    out << '+' << std::endl;
}
