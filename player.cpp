#include "player.h"
#include "view.h"

Player::Player(std::string name, int id) : name(name), id(id) {}

std::string Player::getName() const { return name; }
int Player::getId() const { return id; }

HumanPlayer::HumanPlayer(std::string name, int id) : Player(name, id) {}

int HumanPlayer::chooseMove(const Board& board, GameController& controller) {
        int move;
        std::cout << "Player " << getId() << " (" << getName() << "), choose a move: ";
        std::cin >> move;
        return move;
}

// AIPlayer::AIPlayer(std::string name, int id) : Player(name, id) {}

// int AIPlayer::chooseMove(const Board& board, GameController& controller) {
//     for (int i = 0; i < 6; ++i) {
//         if (board.getPitStones(i + (id == 2 ? 6 : 0)) > 0) {
//             return i;
//         }
//     }
//     return -1; // never happen if isValidMove is called before
// }
