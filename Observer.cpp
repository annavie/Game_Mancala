#include "observer.h"
#include "board.h"
#include <algorithm>

void Subject::attach(Observer* observer) {
    m_observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
}

void Subject::notify(const Board& board) {
    for (auto observer : m_observers) {
        observer->update(board);
    }
}
