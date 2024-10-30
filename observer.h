#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class Board; 

// Observer Pattern
class Observer {
public:
    virtual void update(const Board& board) = 0;
    virtual ~Observer() = default;
};

class Subject {
private:
    std::vector<Observer*> m_observers;
public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const Board& board);
};

#endif // OBSERVER_H
