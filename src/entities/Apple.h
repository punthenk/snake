#pragma once

#include "entities/Position.h"

class Apple {
public:
    Apple(Position init_pos);
    void draw();
    Position getPos();
    bool isEaten();
    void setIsEaten();

private:
    Position pos_;
    bool is_eaten_ = false;
    int cell_size_ = 30;

};
