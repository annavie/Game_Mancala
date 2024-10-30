#include "gameState.h"
#include "gameController.h"
#include <iostream>

GameState::GameState(GameController* ctrl) : controller(ctrl) {}

SetupState::SetupState(GameController* ctrl) : GameState(ctrl) {}

void SetupState::enter() {
    std::cout << "Setting up the game..." << std::endl;
    controller->getBoard().initializeBoard();
    controller->setState(std::make_unique<PlayState>(controller));
}

void SetupState::update() {
        controller->getBoard().initializeBoard();
}

PlayState::PlayState(GameController* ctrl) : GameState(ctrl) {}

void PlayState::enter() {
    std::cout << "Game started! Player 1's turn." << std::endl;
}

void PlayState::update() {
    controller->playTurn();
    if (controller->getBoard().isGameOver()) {
        controller->setState(std::make_unique<EndGameState>(controller));
    }
}

EndGameState::EndGameState(GameController* ctrl) : GameState(ctrl) {}

void EndGameState::enter() {
    controller->announceWinner();
}

void EndGameState::update() {
// controller->announceWinner();
    controller->setState(nullptr); 
}
