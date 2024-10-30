#include "view.h"
#include "board.h"
#include <iostream>

void ConsoleView::update(const Board& board) {
    displayBoard(board);
}

void ConsoleView::displayBoard(const Board& board) {
    std::cout << "         6 5 4 3 2 1" << std::endl;
    std::cout << "          ";
    for (int i = 13; i >= 8; --i) {
        std::cout << board.getPitStones(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "(P2) " << board.getPlayer2Store() << "                   " << board.getPlayer1Store() << " (P1)" << std::endl;

    std::cout << "          ";
    for (int i = 1; i <= 6; ++i) {
        std::cout << board.getPitStones(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "         1 2 3 4 5 6" << std::endl;

    std::cout <<  board.getPlayer1Store() ;
}



void ConsoleView::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}
