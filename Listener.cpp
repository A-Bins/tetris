#include "Listener.h"

#include <conio.h>
#include <Windows.h>


void listen(Listener& listener) {
    if (!_kbhit()) return;

    int init = _getch();
    if (init != MAGIC_KEY) {
        if (init == KEY_C) {
            listener.rotate();
        }

        return;
    }

    switch (_getch()) {
        default: return;

        case UP:
            listener.up();
            break;

        case DOWN:
            listener.down();
            break;

        case RIGHT:
            listener.right();
            break;

        case LEFT:
            listener.left();
            break;
    }

}
