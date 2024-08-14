#include "../include/Include.hpp"

// manager

State* State::currentState = NULL;

State* State::GetState()
{
    return currentState;
}

void State::SetState(State* state)
{
    currentState = state;
}

void State::CleanUp()
{}

// class

State::State(Handler* handler)
{
    this->handler = handler;
}

GameState::GameState(Handler* handler) : State(handler)
{
    world = new World(handler, "res/worlds/World1.txt");
}

void GameState::CleanUp()
{
    delete world;
}

void GameState::Tick()
{

}

void GameState::Render(Window* window)
{

}

MenuState::MenuState(Handler* handler) : State(handler)
{}

void MenuState::Tick()
{

}

void MenuState::Render(Window* window)
{
    
}
