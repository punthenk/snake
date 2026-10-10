#pragma once

#include "Position.h"
#include "Direction.h"
#include <vector>

class Snake {
public:
    Snake(Position start_pos, int start_lenght);
    void update();
    void draw();
    void move();

private:
    std::vector<Position> body_;
    int cell_size_ = 30;
    Direction currect_direction_;

    std::chrono::steady_clock::time_point last_move_ = std::chrono::steady_clock::now();
    std::chrono::milliseconds move_interval_{500};
};
