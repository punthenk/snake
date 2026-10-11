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
    handleInput();
    auto now = std::chrono::steady_clock::now();
    
    if (now - last_move_ >= move_interval_) {
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

void Snake::handleInput() {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_L))   current_direction_ = Direction::Right;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_H))    current_direction_ = Direction::Left;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_K))      current_direction_ = Direction::Up;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_J))    current_direction_ = Direction::Down;
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
