#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "board.h"
#include "gameController.h"
class GameController;
class Player {
protected:
    std::string name;
    int id;

public:
    Player(std::string name, int id);
    virtual int chooseMove(const Board& board, GameController& controller) = 0;
    std::string getName() const;
    int getId() const;
    virtual ~Player() = default;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string name, int id);
    int chooseMove(const Board& board, GameController& controller) override;
};

// class AIPlayer : public Player {
// public:
//     AIPlayer(std::string name, int id);
//     int chooseMove(const Board& board, GameController& controller) override;
// };

#endif // PLAYER_H
