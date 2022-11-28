#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "../board.h"
class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);
  void detach(Observer *o);
  void renderObservers() const;
  virtual char getState(int row, int col) const = 0;
  virtual ~Subject() = default;
};

#endif
