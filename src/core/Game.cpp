#include "Game.h"
#include "raylib.h"

Game::Game(int target_fps) :
    TARGET_FPS(target_fps),
    grid(CELL_SIZE),
    snake(Position(2, 2), 6)
{
    SetTargetFPS(60);
}

void Game::run() {
    while (!WindowShouldClose()) {
        float delta = GetFrameTime();
        update(delta);
        draw();
    }
}

void Game::update(float delta) {
    grid.update();
    snake.update();
}

void Game::draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    grid.draw();
    snake.draw();

    EndDrawing();
}
