#ifndef ENTITY_H_
#define ENTITY_H_

#include "Include.hpp"

class Entity
{
protected:
    Handler* handler;
    float x, y;
    int width, height;
    bool alive;
    Rectangle bounds;
public:
    Entity(Handler*, float, float, int, int);

    virtual void Tick(void) = 0;
    virtual void Render(Window*) = 0;
    virtual void Die(void) = 0;

    void Kill(Entity*);

    Rectangle GetCollisionBounds(float, float);
};

class Creature : public Entity
{
protected:
    float speed;
    float xMove, yMove;
public:
    Creature(Handler*, float, float, int, int);
    void Move();
private:
    void MoveX();
    void MoveY();
};

#endif
