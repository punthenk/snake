#pragma once

#include <raylib.h>
#include "entities/Grid.h"

class Game {
public:
    Game(int targetFps);
    void run();
    void update(float delta);
    void draw();

    static const int WIDTH = 900;
    static const int HEIGHT = 600;

private:
    const int TARGET_FPS = 60;

    Grid grid;
};
