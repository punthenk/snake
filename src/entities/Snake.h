#pragma once

#include "Position.h"
#include <vector>

class Snake {
public:
    Snake(Position start_pos);
    void draw();
    void move(int rows, int colums);

private:
    std::vector<Position> body_;
    int cell_size_ = 30;
};
