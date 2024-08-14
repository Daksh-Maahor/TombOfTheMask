#include "../include/Include.hpp"

Tile** Tile::tiles = new Tile*[256];

Tile* Tile::grassTile = new GrassTile(0, TEXTURE_SIZE, 0);

void Tile::CleanUp()
{
    delete grassTile;

    delete[] tiles;
}

Tile::Tile(int id, int gfxXOffset, int gfxYOffset)
{
    this->id = id;
    this->gfxXOffset = gfxXOffset;
    this->gfxYOffset = gfxYOffset;

    Tile::tiles[id] = this;
}

bool Tile::IsSolid()
{
    return false;
}

void Tile::Render(Window& window, int x, int y)
{
    window.RenderTexture(x, y, TILE_SIZE, TILE_SIZE, gfxXOffset, gfxYOffset);
}

GrassTile::GrassTile(int id, int gfxXOffset, int gfxYOffset) : Tile(id, gfxXOffset, gfxYOffset)
{}
