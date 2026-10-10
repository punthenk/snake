#include "Grid.h"
#include "raylib.h"

Grid::Grid(int cell_size) {
    num_rows_ = 20;
    num_columns_ = 20;
    cell_size_ = cell_size;

    initialize();
}

void Grid::initialize() {
    for (int row = 0; row < num_rows_; row++) {
        for (int column = 0; column < num_columns_; column++) {
            grid_[row][column] = 0;
        }
    }
}


void Grid::update() {
    // Update
}

void Grid::draw() {
    for (int row = 0; row < num_rows_; row++) {
        for (int column = 0; column < num_rows_; column++) {
            int cellValue = grid_[row][column];
            DrawRectangle(column * cell_size_ + 1, row * cell_size_ + 1, cell_size_ - 1, cell_size_ - 1, DARKGREEN);
        }
    }
}


