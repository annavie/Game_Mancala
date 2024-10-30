#include "gameController.h"
#include "player.h"
#include "view.h"
#include <memory>  // For smart pointers

int main() {
    std::unique_ptr<Player> player1 = std::make_unique<HumanPlayer>("Player 1", 1);
    std::unique_ptr<Player> player2 = std::make_unique<HumanPlayer>("Player 2", 2);
    std::unique_ptr<View> view = std::make_unique<ConsoleView>();

    GameController controller(std::move(player1), std::move(player2), std::move(view));

    controller.startGame();

    return 0;
}
