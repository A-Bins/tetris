#include "Player.h"
#include <list>
#include "Render.h"

using namespace std;

void Player::moveX(const int amount) {
    const int except = x + amount;
    previousX = x;
    x = except;

}
void Player::moveY(const int amount) {
    const int except = y + amount;
    previousY = y;
    y = except;
}

void Player::update(Render& render) {
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

    for (auto pair: temp) {
        render.map[pair.second][pair.first] = 2;
    }
    // for (auto& errlist: render.map) {
    //     for (auto& cell: errlist) {
    //
    //         std::wcout << cell;
    //     }
    //     std::wcout << std::endl;
    // }
}
