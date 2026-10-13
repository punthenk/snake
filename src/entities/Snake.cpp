#include "Snake.h"
#include "entities/Position.h"
#include "entities/Grid.h"
#include "raylib.h"
#include <chrono>

Snake::Snake(Position start_pos, int start_lenght) {
    current_direction_ = Direction::Right;

    for (int i = 0; i < start_lenght; i++) {
        Position part = start_pos;
        part.column_ -= i;
        body_.push_back(part);
    }
}

void Snake::update() {
    Direction old_dir = current_direction_;
    handleInput();

    auto now = std::chrono::steady_clock::now();

    if (now - last_move_ >= move_interval_) {
        Direction new_dir = current_direction_;

        if (!input_queue_.empty()) {
            new_dir = input_queue_.front();
            input_queue_.erase(input_queue_.begin());
        }

        current_direction_ = new_dir;

        if (current_direction_ == getOppositeDirection(old_dir))
            current_direction_ = old_dir;

        move();
        last_move_ = now;
    }
}

void Snake::move() {
    Position head = body_[0]; 

    Position new_head = head;
    switch (current_direction_) {
        case Direction::Up:     new_head.column_--; break;
        case Direction::Down:   new_head.column_++; break; 
        case Direction::Right:  new_head.row_++;    break;
        case Direction::Left:   new_head.row_--;    break;
    }

    if (new_head.row_ > Grid::getGridRows() || new_head.row_ < 0)
        is_alive = false;
    else if (new_head.column_ > Grid::getGridColumns() || new_head.column_ < 0)
        is_alive = false;

    for (Position cell : body_) {
        if (new_head.row_    == cell.row_ &&
            new_head.column_ == cell.column_)
        {
            is_alive = false;
        }
    }

    body_.insert(body_.begin(), new_head);
    body_.erase((body_.end() - 1));
}

void Snake::draw() {
    for (Position cell : body_) {
        DrawRectangle(
            cell.row_ * cell_size_ + 1,
            cell.column_ * cell_size_ + 1,
            cell_size_ - 1,
            cell_size_ - 1,
            WHITE
        );
    }
}

void Snake::addDirToInputQueue(Direction dir) {
    if (input_queue_.empty()) {
        input_queue_.push_back(dir);
        return;
    }

    if (input_queue_[input_queue_.size() - 1] != dir)
        input_queue_.push_back(dir);

    if (input_queue_.size() > 3)
        input_queue_.resize(3);
}

void Snake::handleInput() {
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_L)) {
        addDirToInputQueue(Direction::Right);
    }
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_H)) {
        addDirToInputQueue(Direction::Left);
    }
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_K)) {
        addDirToInputQueue(Direction::Up);
    }
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_J)) {
        addDirToInputQueue(Direction::Down);
    }
}

Position Snake::getHeadPos() {
    return body_[0];
}

void Snake::grow() {
    Position part = body_.back();
    body_.push_back(part);
}

int Snake::getBodyLenght() {
    return body_.size();
}

Direction Snake::getOppositeDirection(Direction dir) {
    switch (dir) {
        case Direction::Up:     return Direction::Down;
        case Direction::Down:   return Direction::Up;
        case Direction::Right:  return Direction::Left;
        case Direction::Left:   return Direction::Right;
    }
}
