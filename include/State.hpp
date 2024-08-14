#ifndef STATE_H_
#define STATE_H_

#include "Include.hpp"

class State
{
//manager
private:
    static State* currentState;

public:
    static State* GetState(void);
    static void SetState(State*);

//class

protected:
    Handler* handler;
public:
    State(Handler*);

    virtual void Tick() = 0;
    virtual void Render(Window*) = 0;

    virtual void CleanUp(void);
};

class GameState : public State
{
private:
    World* world;
public:
    GameState(Handler*);
    void Tick() override;
    void Render(Window*) override;
    void CleanUp(void) override;
};

class MenuState : public State
{
public:
    MenuState(Handler*);
    void Tick() override;
    void Render(Window*) override;
};

#endif
