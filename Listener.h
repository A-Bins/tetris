#ifndef KEYEVENTS_H
#define KEYEVENTS_H

#define MAGIC_KEY 224    //상하좌우 화살표가 들어올때 선행되어 들어오는 숫자
#define SPACE 32        //스페이스 키 값
#define KEY_A 97

/**
 * ↑ : 224 -> 72
 * ← : 224 -> 75
 * → : 224 -> 77
 * ↓ : 224 -> 80
 */
enum KEYBOARD {
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};

class Listener {
public:
    virtual ~Listener() = default;
    virtual void up() {}
    virtual void left() {}
    virtual void right() {}
    virtual void down() {}
    virtual void rotate() {}
};

void listen(Listener& listener);



#endif //KEYEVENTS_H
