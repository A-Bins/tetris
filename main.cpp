#include <iostream>
#include <Windows.h>

#include "Key.h"
#include "Listener.h"
#include "Render.h"

using namespace std;

/**
 * 테트리스를 구현하기에 앞서 참고한 자료를 첨부하겠습니다.
 * https://velog.io/@science4588/%ED%85%8C%ED%8A%B8%EB%A6%AC%EC%8A%A4-%EA%B0%9C%EB%B0%9C-2%EC%9D%BC%EC%B0%A8
 *
 * 해당 글을 많이 참고하였는데요, 처음에는 테트리스는 블럭들이 있고 이를 회전하고 이동하는데, 처음에 3차원 배열 int로 구현할까 했습니다.
 * 하지만 회전을 구현을 어떻게하지? 라는 생각에 구글링해보고 해당 블로그 글을 모티브로 작성하게 됐습니다.
 *
 * 해당 글에서는 저와 똑같이 3차원으로 구성하려 했으나, 회전에서 막혀서 아예 이분은 하드코딩으로 90, 180, 270, 360을 모두 구현했습니다.
 * 예를 들어
 * {
 *  { 3차원 배열(90도)  },
 *  { 3차원 배열(180도) },
 *  { 3차원 배열(270도) },
 *  { 3차원 배열(360도) }
 * }
 * 이렇게 나타냅니다. 하지만 저는 하드코딩을 하지 않고 구현은 못할까? 라는 생각에
 *
 *
 */

int main() {
    Render render;
    render.init();

    Key key;

    // while (true) {
        // cout << "!!";
        render.draw();
        // listen(key);
        // cout << "!";
        // Sleep(1000);
    // }
    Sleep(10000);

    return 0;
}
