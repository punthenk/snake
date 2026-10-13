#pragma once

#include "Position.h"
#include "Direction.h"
#include <vector>
#include <chrono>

class Snake {
public:
    Snake(Position start_pos, int start_lenght);
    void update();
    void draw();
    void move();
    void handleInput();
    Position getHeadPos();
    void grow();
    int getBodyLenght();
    Direction getOppositeDirection(Direction dir);

    bool is_alive = true;

private:
    std::vector<Position> body_;
    int cell_size_ = 30;
    Direction current_direction_;
    bool allow_input_ = true;
    std::vector<Direction> input_queue_;

    std::chrono::steady_clock::time_point last_move_ = std::chrono::steady_clock::now();
    std::chrono::milliseconds move_interval_{200};

    void addDirToInputQueue(Direction dir);
};
