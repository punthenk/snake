#include "Game.h"
#include "entities/Apple.h"
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
    food_generator_.update();

    Apple* apple = food_generator_.current_apple_;

    if (snake.getHeadPos().row_     == apple->getPos().row_ &&
        snake.getHeadPos().column_  == apple->getPos().column_) 
    {
        apple->setIsEaten();
        snake.grow();
    }
}

void Game::draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    grid.draw();
    snake.draw();
    if (food_generator_.current_apple_ != nullptr)
        food_generator_.current_apple_->draw();

    EndDrawing();
}
