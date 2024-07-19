#ifndef KEY_H
#define KEY_H
#include "Listener.h"


class Key final : public Listener {
public:
    void up() override;
    void down() override;
    void right() override;
    void left() override ;
    void rotate() override;
};




#endif //KEY_H
