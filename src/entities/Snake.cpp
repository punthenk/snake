#include "Snake.h"
#include "entities/Position.h"
#include "raylib.h"
#include <iostream>
#include <string>

Snake::Snake(Position start_pos) {
    body_.push_back(start_pos); 
}

void Snake::draw() {
    for (Position cell : body_) {
        std::cout << "ROW:       " << std::to_string(cell.row_) << "\n";
        std::cout << "COLUMN:    " << std::to_string(cell.column_) << "\n";
        std::cout << "CELL_SIZE: " << std::to_string(cell_size_) << "\n";
        DrawRectangle(
            cell.row_ * cell_size_ + 1,
            cell.column_ * cell_size_ + 1,
            cell_size_ - 1,
            cell_size_ - 1,
            WHITE
        ); 
    }
}
