#include "../include/Include.hpp"

Window::Window(const char* title, int w, int h) : window(NULL), width(w), height(h)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS);

    if (window == NULL)
    {
        std::cout << "Window failed to init. Error : " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

int Window::GetRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex(window);

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}

void Window::CleanUp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

SDL_Texture* Window::LoadTexture(const char* path)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, path);

    if (texture == NULL)
    {
        std::cout << "Failed to load texture. Error : " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Window::RenderTexture(int x, int y, int width, int height, int xOff, int yOff)
{
    SDL_Rect srcRect = {xOff, yOff, TEXTURE_SIZE, TEXTURE_SIZE};
    SDL_Rect destRect = {x, y, width, height};

    SDL_RenderCopy(renderer, Assets::sheet, &srcRect, &destRect);
}

void Window::ClearScreen()
{
    SDL_RenderClear(renderer);
}

void Window::Display()
{
    SDL_RenderPresent(renderer);
}
