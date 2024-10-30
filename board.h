#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <numeric>
#include "observer.h"

class Board : public Subject {
private:
    std::vector<int> m_pits;
    // int m_player1Store;
    // int m_player2Store;

public:
    Board();
    void initializeBoard();
    int getPitStones(int pitIndex) const;
    void moveStonesFrom(int pitIndex);
    bool isGameOver() const;
    int getWinner() const;
    int getPlayer1Store()const;
    int getPlayer2Store()const;

    
};

#endif // BOARD_H
