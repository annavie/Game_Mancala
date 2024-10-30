#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <memory>
#include <stack>
#include <functional>
#include "board.h"
#include "player.h"
#include "view.h"
#include "gameState.h"
class Player;
class GameController {
private:
    Board board;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    Player* currentPlayer ;
    std::unique_ptr<View> view;
    std::stack<std::function<void()>> undoStack;
    std::unique_ptr<GameState> currentState;

public:
    GameController(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2, std::unique_ptr<View> v);
    void setState(std::unique_ptr<GameState> newState);
    void startGame();
    void playTurn();
    void switchPlayer();
    bool isValidMove(int move);
    void executeMove(int move);
    void announceWinner();
    Board& getBoard();
    View* getView();
};

#endif // GAMECONTROLLER_H
