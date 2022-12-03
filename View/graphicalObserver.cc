#include "graphicalObserver.h"
#include "window.h"
GraphicalObserver::GraphicalObserver(ChessStudio* studio, Xwindow * window): studio{studio}, window{window}
{
    studio->attach(this);
};

GraphicalObserver::~GraphicalObserver(){};

void GraphicalObserver::render() {  

    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {

            //fill the background with tiles 
            if ((i + j) % 2 == 0){
                window->fillRectangle(j * 30, i * 30, 30, 30, Xwindow::White);
            } else {
                window->fillRectangle(j * 30, i * 30, 30, 30, Xwindow::Green);
            }

            //fill the tiles with their letter
            char letter = studio->getState(i, j);
            std::string s(1, letter);
            window->drawString((j * 30) + 13, (i * 30) + 20, s); //offset j and i to put the letter in the middle of the tile 
        }
    }
};
