#ifndef GRAPHICAL_OBSERVER_H
#define GRAPHICAL_OBSERVER_H
#include <iostream>
//#include "board.h"
#include "window.h"
#include "observer.h"

class Xwindow;
class GraphicalObserver : public Observer {
    ChessStudio* studio; 
    Xwindow* window;
public:
    GraphicalObserver(ChessStudio* studio, Xwindow* window);
    ~GraphicalObserver();
    void render() override;
};

#endif
