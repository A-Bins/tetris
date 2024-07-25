#include "Player.h"

#include <iostream>
#include <list>
#include "Render.h"

using namespace std;

void Player::moveX(const int amount) {
    const int except = x + amount;
    if (collide(except, y)) return;

    previousX = x;
    x = except;

}
void Player::moveY(const int amount) {
    const int except = y + amount;
    if (collide(x, except)) return;

    previousY = y;
    y = except;
}

void Player::rotate() {

}


void Player::update() {
    list<pair<int, int>> temp;
    const int deltaX = x - previousX, deltaY = y - previousY;

    int y = this->y;
    for (auto& y_cell : chunk.cell) {
        int x = this->x;
        for (auto& x_cell: y_cell) {
            if (x_cell == 1) {
                render.map[y - deltaY][x - deltaX] = 0;
                temp.emplace_front(x, y);
            }
            ++x;
        }
        ++y;
    }
    previousX = this->x;
    previousY = this->y;

    for (const auto [x, y]: temp) {
        render.map[y][x] = 2;
    }
}

bool Player::collide(const int exceptX, const int exceptY) {
    int y = exceptY;
    for (auto& y_cell : chunk.cell) {
        int x = exceptX;
        for (auto& x_cell: y_cell) {
            if (x_cell == 1 && render.map[y][x] == 1)
                return true;
            ++x;
        }
        ++y;
    }
    return false;
}
