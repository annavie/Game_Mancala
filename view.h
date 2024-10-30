#ifndef VIEW_H
#define VIEW_H

#include <string>
#include<iostream>
#include "observer.h"


class View : public Observer {
public:
    virtual void displayMessage(const std::string& message) = 0;
    // virtual int getPlayerInput() = 0;
    virtual ~View() = default;
};

class ConsoleView : public View {
public:
    void update(const Board& board) override;
    void displayBoard(const Board& board);
    void displayMessage(const std::string& message) override;
};

#endif // VIEW_H
