#include "Player.h"

#include <Windows.h>

#include "Render.h"


void Player::update(Render& render) {
    int x = 0;
    int y = 0;
    for (auto& y_cell : chunk.cell) {
        for (auto& x_cell: y_cell) {
            render.map[y][x] = 2;
            ++x;
        }
        ++y;
    }
}


void Player::loop(Render& render) {
    while (true) {
        update(render);
        Sleep(1000);
    }
}