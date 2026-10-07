#include "Grid.h"
#include "raylib.h"

#include <cstdio>
#include <iostream>

Grid::Grid() {
    numRows = 20;
    numColumns = 20;
    cellSize = 30;

    initialize();
}

void Grid::initialize() {
    for (int x = 0; x < numRows; x++) {
        for (int y = 0; y < numColumns; y++) {
            grid[x][y] = 0;
        }
    }
}


void Grid::update() {
    // Update
}

void Grid::draw() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numRows; column++) {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, GREEN);
        }
    }
}


