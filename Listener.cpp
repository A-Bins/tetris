#include "Listener.h"

#include <cstdio>
#include <Windows.h>


void listen(Listener& listener) {
    int init = getchar();
    if (init != MAGIC_KEY) {
        if (init == KEY_C) {
            listener.rotate();
        }

        return;
    }

    switch (getchar()) {
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
