#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "chessStudio.h"

//class chessStudio;
class Observer {
  public:
    virtual void render() = 0;
    virtual ~Observer() = default;
};
#endif
