#ifndef GAME_H_
#define GAME_H_

#include "Include.hpp"

class Game
{
private:
    const char* title;
    int width, height;

    Window* window;

    bool running = false;
    InputManager inputManager;

    Handler* handler;

    State* gameState;
    State* menuState;
private:
    void Init(void);
    void CleanUp(void);

    void Run(void);
    void Stop(void);

    void Update(void);
    void Render(void);
public:
    Game(const char*, int, int);
    void Start(void);

    int GetWidth() { return width; }
    int GetHeight() { return height; }

    InputManager* GetInputManager() { return &inputManager; }
};

class Handler
{
private:
    Game* game;
public:
    Handler(Game*);
    int GetWidth() { return game->GetWidth(); }
    int GetHeight() { return game->GetHeight(); }
    InputManager* GetInputManager() { return game->GetInputManager(); }
};

#endif
