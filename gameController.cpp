#include "gameController.h"
#include "board.h"
#include <iostream>

GameController::GameController(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2, std::unique_ptr<View> v)
    : player1(std::move(p1)), player2(std::move(p2)), view(std::move(v)) {
    currentPlayer = player1.get();
    currentState = std::make_unique<SetupState>(this);
}

void GameController::setState(std::unique_ptr<GameState> newState) {
    std::cout << "setState function call" << std::endl;
    currentState = std::move(newState);
    currentState->enter();
}

void GameController::startGame() {
    std::cout << "startGame  function call" << std::endl;
    currentState->enter();  // Enter the initial game state (SetupState)

    while (currentState) {  // Continue until there is no current state (i.e., game over)
        // Check if the game is over before taking any turns
        if (board.isGameOver()) {
            announceWinner();  // Announce the winner
            setState(std::make_unique<EndGameState>(this)); // Change to EndGameState
            break;  // Exit the loop since the game is now in the end state
        }

        // Call playTurn to let the current player make a move
        currentState->update();  // Update the current state (e.g., play turn)
    }
}


void GameController::playTurn() {
    std::cout << "playTurn function call" << std::endl;

    int move = currentPlayer->chooseMove(board, *this);
    if (isValidMove(move)) {
        executeMove(move);
        if (auto consoleView = dynamic_cast<ConsoleView*>(view.get())) {
            consoleView->displayBoard(board);  // Display the updated board
        }
        if (board.isGameOver()) {
            announceWinner();
        } else {
            switchPlayer();  // Switch turns only if the game is not over
        }

    } else {
        view->displayMessage("Invalid move. Try again.");
    }
}
void GameController::switchPlayer() {
    std::cout << "Switch player function call" << std::endl;

    currentPlayer = (currentPlayer == player1.get()) ? player2.get() : player1.get();
}

bool GameController::isValidMove(int move) {
    std::cout << "isValidMove function call" << std::endl;

    return move >= 0 && move <= 6 && board.getPitStones(move + (currentPlayer->getId() == 2 ? 7 : 0)) > 0;
}

void GameController::executeMove(int move) {
    std::cout << "executeMove function call" << std::endl;

    board.moveStonesFrom(move + (currentPlayer->getId() == 2 ? 7 : 0));
}

void GameController::announceWinner() {
    std::cout << "announceWinner function call" << std::endl;

    if (view == nullptr) {
        std::cerr << "Error: view is not initialized." << std::endl;
        return;
    }

    int winner = board.getWinner();
    if (winner == 1) {
        view->displayMessage("Player 1 wins!");
    } else if (winner == 2) {
        view->displayMessage("Player 2 wins!");
    } else {
        view->displayMessage("It's a draw!");
    }
}

Board& GameController::getBoard() {
    std::cout << "getBoard function call" << std::endl;

    return board;
}

View* GameController::getView() {
    std::cout << "getView function call" << std::endl;

    return view.get();
}
