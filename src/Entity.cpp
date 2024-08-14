#include "../include/Include.hpp"

Entity::Entity(Handler* handler, float x, float y, int width, int height)
{
    this->handler = handler;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    alive = true;

    bounds = {0, 0, width, height};
}

void Entity::Kill(Entity* other)
{
    other->alive = false;
    other->Die();
}

Rectangle Entity::GetCollisionBounds(float xOffset, float yOffset)
{
    Rectangle bound = {x + bounds.x + xOffset, y + bounds.y + yOffset, bounds.w, bounds.h};

    return bound;
}

Creature::Creature(Handler* handler, float x, float y, int width, int height) : Entity(handler, x, y, width, height)
{
    speed = DEFAULT_CREATURE_SPEED;
    xMove = 0;
    yMove = 0;
}

void Creature::Move()
{
    MoveX();
    MoveY();
}

void Creature::MoveX()
{
    x += xMove;
}

void Creature::MoveY()
{
    y += yMove;
}
