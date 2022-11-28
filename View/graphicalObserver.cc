#include "graphicalObserver.h"
#include "window.h"
GraphicalObserver::GraphicalObserver(ChessStudio* studio, Xwindow * window): studio{studio}, window{window}
{
    studio->attach(this);
};

GraphicalObserver::~GraphicalObserver(){
    delete window;
}
void GraphicalObserver::render() {  
    for (size_t i = 0; i < BOARD_SIZE; ++i) {
        for (size_t j = 0; j < BOARD_SIZE; ++j) {
            char result = studio->getState(i, j);
            if (isdigit(result)){
                window->fillRectangle(j * 10, i * 10, 10, 10, Xwindow::Blue);
            } else if (islower(result)){
                window->fillRectangle(j * 10, i * 10, 10, 10, Xwindow::Red);
            } else if (isupper(result)){
                window->fillRectangle(j * 10, i * 10, 10, 10, Xwindow::Green);
            } else if (result == ' '){
                window->fillRectangle(j * 10, i * 10, 10, 10, Xwindow::White);
            } else {
                window->fillRectangle(j * 10, i * 10, 10, 10, Xwindow::Black);
            }
        }
    }
}
