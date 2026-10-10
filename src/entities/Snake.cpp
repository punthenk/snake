#include "Snake.h"
#include "entities/Position.h"
#include "raylib.h"
#include <chrono>

Snake::Snake(Position start_pos, int start_lenght) {
    currect_direction_ = Direction::Right;

    for (int i = 0; i < start_lenght; i++) {
        Position part = start_pos;
        part.column_ -= i;
        body_.push_back(part);
    }
}

void Snake::update() {
    auto now = std::chrono::steady_clock::now();
    
    if (now - last_move_ >= move_interval_) {
        move();
        last_move_ = now;
    }
}

void Snake::move() {
    Position head = body_[0]; 
    Direction direction = currect_direction_;

    Position new_head = head;
    switch (direction) {
        case Direction::Up:     break;
        case Direction::Down:   break; 
        case Direction::Right:  new_head.row_++; break;
        case Direction::Left:   break;
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
