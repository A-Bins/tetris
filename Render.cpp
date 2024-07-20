#include "Render.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

using namespace std;

void gotoxy(const short x, const short y) {
    const COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void disableCursor() {
    CONSOLE_CURSOR_INFO ConsoleCursor;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(console, &ConsoleCursor);
}

void Render::init() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    disableCursor();
    system("mode con cols=20 lines=20 | title Tetris 20307");

}
void Render::draw() {
    gotoxy(0, 0);
    int column = 0;

    for (const auto& rows: map) {
        for (const auto& row: rows) {
            if (row == 1)
                wcout << L"■";
            else if (row == 0)
                wcout << " ";
            else if (row == 2)
                wcout << L"□";
        }

        wcout << endl;
        ++column;
    }
}

void Render::queue() {

}