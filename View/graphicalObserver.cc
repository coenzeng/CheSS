#include "graphicalObserver.h"
#include "window.h"
#include <algorithm>
#include <string>
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
                window->fillRectangle(j * 30 + 30, i * 30 + 30, 30, 30, Xwindow::White);
            } else {
                window->fillRectangle(j * 30 + 30, i * 30 + 30, 30, 30, Xwindow::Green);
            }

            //fill the tiles with their letter
            char letter = studio->getState(i, j);
            std::string s(1, letter);
            window->drawString((j * 30 + 30) + 13, (i * 30 + 30) + 20, s); //offset j and i to put the letter in the middle of the tile 
        }
    }
    /*
    parameters
    dispX*30, dispY*30, sizeX, sizeY
    */
    std::string rowNum;
    window->fillRectangle(30, 0, 240, 30, Xwindow::White);
    window->fillRectangle(0, 0, 30, 270, Xwindow::White);
    int vertSpacer = 1;
    for(int i = 8; i >= 1; i--){
        rowNum = std::to_string(i);
        window->drawString(13, 20 + (vertSpacer*30), rowNum);
        vertSpacer++;
    }

    int horizSpacer = 1;
    std::string alphabet = "ABCDEFGH";
    std::string colLetter;
    for(int i = 1; i <= 8; i++){
        colLetter = alphabet[i-1];
        window->drawString(13 + (horizSpacer*30), 20 , colLetter);
        horizSpacer++;
    }
};
