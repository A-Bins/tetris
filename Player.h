#ifndef PLAYER_H
#define PLAYER_H
#include "Chunk.h"
#include "Render.h"


class Player {

public:

    int x, y;
    Chunk chunk;


    void update(Render& render);
    void loop(Render& render);
};



#endif //PLAYER_H
