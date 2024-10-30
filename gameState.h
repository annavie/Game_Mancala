#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameController; // Forward declaration

class GameState {
protected:
    GameController* controller;

public:
    GameState(GameController* ctrl);
    virtual void enter() = 0;
    virtual void update() = 0;
    virtual ~GameState() = default;
};

class SetupState : public GameState {
public:
    SetupState(GameController* ctrl);
    void enter() override;
    void update() override;
};

class PlayState : public GameState {
public:
    PlayState(GameController* ctrl);
    void enter() override;
    void update() override;
};

class EndGameState : public GameState {
public:
    EndGameState(GameController* ctrl);
    void enter() override;
    void update() override;
};

#endif // GAMESTATE_H
