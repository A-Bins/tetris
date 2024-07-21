#include "Key.h"

#include <iostream>

using namespace std;

void Key::up() {
    int except = player.y - 1;
    if (player.render.map[except][player.x] == 1) return;

    player.moveY(-1);
}

void Key::down() {
    int except = player.y + 1;
    if (player.render.map[except][player.x] == 1) return;

    player.moveY(1);
}

void Key::right() {
    int except = player.x + 1;
    if (player.render.map[player.y][except] == 1) return;

    player.moveX(1);
}

void Key::left() {
    int except = player.x - 1;
    if (player.render.map[player.y][except] == 1) return;

    player.moveX(-1);
}

void Key::rotate() {

}

