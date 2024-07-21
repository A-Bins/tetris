#include <iostream>
#include <thread>
#include <Windows.h>

#include "Key.h"
#include "Listener.h"
#include "Player.h"
#include "Render.h"

using namespace std;

bool alive = true;
/**
 * 테트리스를 구현하기에 앞서 참고한 자료를 첨부하겠습니다.
 * https://velog.io/@science4588/%ED%85%8C%ED%8A%B8%EB%A6%AC%EC%8A%A4-%EA%B0%9C%EB%B0%9C-2%EC%9D%BC%EC%B0%A8
 *
 * 해당 글을 많이 참고하였는데요, 처음에는 테트리스는 블럭들이 있고 이를 회전하고 이동하는데, 처음에 3차원 배열 int로 구현할까 했습니다.
 * 하지만 회전을 구현을 어떻게하지? 라는 생각에 구글링해보고 해당 블로그 글을 모티브로 작성하게 됐습니다.
 *
 * 해당 글에서는 저와 똑같이 도형당 2차원 ( 총 3차원 ) 으로 구성하려 했으나, 회전에서 막혀서 아예 이분은 하드코딩으로 90, 180, 270, 360을 모두 구현했습니다.
 * 예를 들어
 * {
 *  { 2차원 배열(90도)  },
 *  { 2차원 배열(180도) },
 *  { 2차원 배열(270도) },
 *  { 2차원 배열(360도) }
 * }
 *
 * 이렇게 나타냅니다. 하지만 저는 하드코딩을 하지 않고 구현은 못할까? 라는 생각에 여러가지를 조사해봤습니다
 * 기존 방식에서 문제가 생긴 것은
 *  1. 코드가 너무 더러움.
 *   - 아무래도 2차원 배열을 숫자로 나타내려고 하다보니까 코드가 50줄가까이 들어가며 심한 하드코딩이 되어버려서 가독성을 헤칩니다.
 *  2. 가변성이 없음.
 *   - 만약에 블럭을 많이 추가하면?
 *   - 만약에 블럭이 바뀌면?
 *   - 만약에 블럭의 크기들이 바뀌면?
 *   이에 대해서 대처하기 껄끄럽습니다.
 *
 *  이 문제를 해결하기 위해서 비트마스크 방법을 채용한게 있습니다.
 *  Bitmask를 이용한 테트리스 도형 회전은 7개의 테트리스 도형에 대한 모든 회전(4가지) 정보를 가지고 있는 것으로
 *  데이터 양을 줄이고 관리를 편리하게 하기 위해 도형 정보를 bit로 변환해서 저장합니다 (16bit)
 *
 *  예시로
 *  도형 부분을 1, 아닌 부분을 0으로 하면
 *
 *  0 1 0 0
 *  0 1 0 0
 *  0 1 1 0
 *  0 0 0 0
 *
 *  즉, L 자 도형은 2 진수로 0100 0100 0110 0000 이 되고
 *  16 진수로 4460 이 됩니다.
 *
 *  여기까지는 좋았습니다
 *  제가 원하던 기존 캐싱 방식에서 가독성 부분을 헤치지 않고 간단하게 16진수를 사용하는 이유만 이해하면 흐름자체는 이해하기 쉽기 때문입니다
 *
 *  그러나 여전히 하드코딩 방식에서 벗어나볼 순 없을까? 란 물음이 생겼고 아예 회전을 알고리즘으로 구현한 사례를 찾을 수 있었습니다.
 *
 *
 */

void playerUpdate(Player& player, Render& render) {
    while (true) {
        player.update(render);
        Sleep(100);
    }
}

void draw(Render& render) {
    while (true) {
        render.draw();
        Sleep(100);
    }
}
int main() {
    Render render;
    render.init();
    Chunk chunk(0, 0, Chunk::I, Chunk::i);
    Player player(2, 0, render, chunk);

    thread playerThread(playerUpdate, ref(player), ref(render));
    thread drawThread(draw, ref(render));

    Key key(player);
    while (alive) {
        listen(key);
        Sleep(100);
    }

    alive = false;

    return 0;
}
