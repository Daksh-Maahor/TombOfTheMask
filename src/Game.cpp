#include "../include/Include.hpp"

Game::Game(const char* title, int width, int height)
{
    this->title = title;
    this->width = width;
    this->height = height;
}

void Game::Init()
{
    window = new Window(title, width, height);
    Assets::Init(window);

    handler = new Handler(this);

    gameState = new GameState(handler);
    menuState = new MenuState(handler);
    State::SetState(gameState);
}

void Game::Update()
{
    if (State::GetState() != NULL)
    {
        State::GetState()->Tick();
    }
}

void Game::Render()
{
    window->ClearScreen();

    if (State::GetState() != NULL)
    {
        State::GetState()->Render(window);
    }

    window->Display();
}

void Game::Run()
{
    Init();

    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = Utils::HireTimeInSeconds();

    // for my clock
    int fps = 60;
    double timePerTick = 1000/fps;
    double delta = 0;
    long now;
    long lastTime = SDL_GetTicks();
    long timer = 0;
    int ticks = 0;

    while (running)
    {
        int startTicks = SDL_GetTicks();

        float newTime = Utils::HireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    running = false;
                }
                else if (event.type == SDL_MOUSEBUTTONDOWN)
                {

                }
                else if (event.type == SDL_MOUSEBUTTONUP)
                {

                }
                else if (event.type == SDL_MOUSEMOTION)
                {
                    inputManager.mouseX = event.motion.x;
                    inputManager.mouseY = event.motion.y;
                }
                else if (event.type == SDL_KEYDOWN)
                {
                    if (!(event.key.keysym.sym == SDLK_SPACE))
                    {
                        inputManager.keys[event.key.keysym.sym] = true;
                    }
                }
                else if (event.type == SDL_KEYUP)
                {
                    if (!(event.key.keysym.sym == SDLK_SPACE))
                    {
                        inputManager.keys[event.key.keysym.sym] = false;
                    }
                    else
                    {
                        inputManager.keys[event.key.keysym.sym] = !inputManager.keys[event.key.keysym.sym];
                    }
                }
            }

            accumulator -= timeStep;
        }
        //my clock below

        now = SDL_GetTicks();
        delta += (now - lastTime) / timePerTick;
        timer += (now - lastTime);
        lastTime = now;

        if (delta >= 1)
        {
            //update here
            Update();
            Render();
            //update above
            ticks++;
            delta--;
        }

        if (timer >= 1000)
        {
            std::cout << "Ticks and Frames : " << ticks << std::endl;
            ticks = 0;
            timer = 0;
        }

        //my clock above

        int frameTicks = SDL_GetTicks() - startTicks;

        if (frameTicks < 1000 / window->GetRefreshRate())
        {
            SDL_Delay(1000 / window->GetRefreshRate() - frameTicks);
        }
    }

    Stop();
}

void Game::Start()
{
    if (running)
    {
        return;
    }
    running = true;
    Run();
}

void Game::Stop()
{
    CleanUp();
}

void Game::CleanUp()
{
    Tile::CleanUp();
    Assets::CleanUp();

    gameState->CleanUp();

    delete gameState;
    delete menuState;
    delete handler;
    delete window;
}

Handler::Handler(Game* game)
{
    this->game = game;
}
