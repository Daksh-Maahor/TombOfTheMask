#ifndef TILE_H_
#define TILE_H_

class Tile
{
// static
public:
    static Tile** tiles;

    static Tile* grassTile;

    static void CleanUp();

// class

private:
    int id;
    int gfxXOffset, gfxYOffset;
public:
    Tile(int, int, int);
    bool IsSolid(void);
    void Render(Window&, int, int);
};

class GrassTile : public Tile
{
public:
    GrassTile(int, int, int);
};

#endif
