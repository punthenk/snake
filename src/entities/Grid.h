#pragma once

#include <raylib.h>

class Grid {
public:
    Grid(int cell_size);
    void initialize();
    void update();
    void draw();
    bool isCellEmpty(int row, int column);
    int grid_[50][50];

private:
    int num_rows_;
    int num_columns_;
    int cell_size_;
};
