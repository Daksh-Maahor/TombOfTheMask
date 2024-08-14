#ifndef GFX_H_
#define GFX_H_

#include "Include.hpp"

namespace Assets
{
    inline SDL_Texture* sheet;

    inline static void Init(Window* window)
    {
        sheet = window->LoadTexture("res/gfx/sheet.png");
    }

    inline static void CleanUp()
    {
        SDL_DestroyTexture(sheet);
    }
}

#endif
