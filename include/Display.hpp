#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "Include.hpp"

class Window
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    int width, height;
public:
    Window(const char*, int, int);
    void CleanUp(void);

    int GetRefreshRate(void);

    void ClearScreen(void);
    void Display(void);

    SDL_Texture* LoadTexture(const char*);
    void RenderTexture(int, int, int, int, int, int);
};

#endif
