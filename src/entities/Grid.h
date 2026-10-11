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

    static int getGridRows();
    static int getGridColumns();

private:
    static int num_rows_;
    static int num_columns_;
    int cell_size_;
};
