#pragma once

#include <raylib.h>
#include "entities/FoodGenerator.h"
#include "entities/Grid.h"
#include "entities/Snake.h"

class Game {
public:
    Game(int target_fps);
    void run();
    void update(float delta);
    void draw();
    void resetGame();

    static const int WIDTH = 600;
    static const int HEIGHT = 600;

    const int CELL_SIZE = 30;

private:
    const int TARGET_FPS = 60;

    Grid grid_;
    Snake snake_;
    FoodGenerator food_generator_;
};
