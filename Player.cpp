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

/**
 *
 *   pivot(x,y)에서 회전 공식을 사용한 변환:
 *
 *
 *   90도 시계 방향으로 회전한 점 (x1, y1)는
 *   (y1, -x1)입니다. - (1) 행렬 변환Q
 *
 *   점 (x1, y1)를 피벗 (x, y)을 기준으로 이동시키면
 *   (x1 - x, y1 - y)가 됩니다. - (2) 상대적 좌표 이동
 *
 *   이동한 좌표를 90도 시계 방향으로 회전하면:
 *
 *  (x1 - x, y1 - y)는  (1)
 *     X       Y
 *  (y1 - y, - (x1 - x))로 변환됩니다.
 *     Y         -X
 *
 *  원래의 피벗 위치로 다시 이동시키면 - (2)의 반대방향 이동
 *  새로운 좌표는 (x + (y1 - y), y - (x1 - x))가 됩니다.
 *          X + x =     x + (y1 - y)
 *          Y + y =     y - ( x1-x )
 *
 *
 *
 *인덱스  x 0 1 2 3       0 1 2 3
 *     y
 *     0   0 0 1 0    0  0 0 0 0
 *     1   0 0 2 0 -> 1  4 3 2 1
 *     2   0 0 3 0    2  0 0 0 0
 *     3   0 0 4 0    3  0 0 0 0
 *
 * 90도 시계방향 회전으로 변환되었을때 인덱스가 변화되는 정도를 확인해보면
 * pivot을 (2, 1)로 둠
 *         x,  y
 *
 *       x  y      x  y
 * 1 -> (2, 0) -> (3, 1)
 * 2 -> (2, 1) -> (2, 1)
 * 3 -> (2, 2) -> (1, 1)
 * 4 -> (2, 3) -> (0, 1)
 *
 */
void Player::rotate() const {
    const int pivot_x = chunk.x;
    const int pivot_y = chunk.y;

    list<pair<int, int>> cells;
    list<pair<int, int>> remove;
    list<pair<int, int>> remove2;

    int y1 = 0;
    for (auto& y_cell : chunk.cell) {
        int x1 = 0;
        for (auto& x_cell: y_cell) {
            if (x_cell == 1) {
                // 원점을 기준으로 피벗 이동
                int temp_x = x1 - pivot_x;
                int temp_y = y1 - pivot_y;

                // 90도 회전
                int rotated_x = temp_y;
                int rotated_y = -temp_x;

                // 다시 피벗 위치로 이동
                int new_x = rotated_x + pivot_x;
                int new_y = rotated_y + pivot_y;

                if (render.map[new_y + y][new_x + x] == 1) return;

                remove2.emplace_front(x1, y1);
                remove.emplace_front(x1 + x, y1 + y);

                cells.emplace_front(new_x, new_y);
            }
            ++x1;
        }
        ++y1;
    }

    for (const auto& [x, y] : remove2) {
        chunk.cell[y][x] = 0;
    }

    for (const auto& [x, y] : remove) {
        render.map[y][x] = 0;
    }

    for (const auto& [x, y] : cells) {
        chunk.cell[y][x] = 1;
    }

    // wcout << endl;
    // for (auto& y_cell : chunk.cell) {
    //     wcout << endl;
    //     for (auto& x_cell: y_cell) {
    //         wcout << x_cell;
    //     }
    //     wcout << endl;
    // }
}


void Player::update() {
    list<pair<int, int>> temp;
    const int deltaX = x - previousX, deltaY = y - previousY;

    int y = this->y;
    for (const auto& y_cell : chunk.cell) {
        int x = this->x;
        for (const auto& x_cell: y_cell) {
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
