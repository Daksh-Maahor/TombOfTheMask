#include "../include/Include.hpp"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL failed to init. Error : " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "IMG failed to init. Error : " << SDL_GetError() << std::endl;
        return 1;
    }

    Game game("Tomb Of The Mask", 640, 640);
    game.Start();

    return 0;
}
