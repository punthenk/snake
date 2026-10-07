#pragma once

#include <raylib.h>

class Grid {
public:
    Grid();
    void initialize();
    void update();
    void draw();

    int numRows;
    int numColumns;
    int cellSize;

    int grid[50][50];

private:
};
