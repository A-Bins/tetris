#ifndef PLAYER_H
#define PLAYER_H
#include "Chunk.h"
#include "Render.h"


class Player {

public:
    Player(int x, int y, Render& render, Chunk& chunk): x(x), y(y), render(render), chunk(chunk) {}

    int x, y;
    Render& render;
    Chunk& chunk;

    void moveX(int amount);
    void moveY(int amount);
    void rotate();
    void update();
    bool collide(int exceptX, int exceptY);

private:
    int previousX = x, previousY = y;
};



#endif //PLAYER_H
