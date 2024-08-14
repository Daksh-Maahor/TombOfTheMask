#ifndef WORLD_H_
#define WORLD_H_

#include "../include/Include.hpp"

class World
{
private:
    Handler* handler;
    int width, height;
    int spawnX, spawnY;

    int* tiles;
public:
    World(Handler*, std::string);
    void Tick(void);
    void Render(Window&);
};

#endif
