#include "Key.h"

#include <iostream>

using namespace std;

void Key::up() {
    player.moveY(-1);
}

void Key::down() {
    player.moveY(1);
}

void Key::right() {
    player.moveX(1);
}

void Key::left() {
    player.moveX(-1);
}

void Key::rotate() {
    player.rotate();
}

