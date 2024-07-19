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
    disableCursor();
    _setmode(_fileno(stdout), _O_U16TEXT);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    system("mode con cols=160 lines=40 | title 테트리스 20307 김우균");

}
void Render::draw() {
    system("cls");
    int column = 0;

    for (auto& rows: map) {
        for (auto& row: rows) {
            if (row == 1)
                wcout << L"■";
            else if (row == 0)
                wcout << "11";
            else if (row == 2)
                wcout << L"□";
        }

        wcout << endl;
        ++column;
    }
    wcout <<column;
}

void Render::queue() {

}