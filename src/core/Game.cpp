#include "Game.h"
#include "entities/Apple.h"
#include "raylib.h"
#include <string>

using std::string;

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
    if (!snake.is_alive)
        return;

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

    if (snake.is_alive)
        DrawText((std::to_string(snake.getBodyLenght())).c_str(), 20, 20, 20, WHITE);

    if (!snake.is_alive) {
        string text = "YOU DIED";
        Vector2 text_size = MeasureTextEx(GetFontDefault(), text.c_str(), 50, 5);
        int text_pos_x = (Game::WIDTH  / 2) - (text_size.x / 2);
        int text_pos_y = (Game::HEIGHT / 2) - (text_size.y / 2);
        DrawText(text.c_str(), text_pos_x, text_pos_y, 50, WHITE);

        DrawText(("Score: " + std::to_string(snake.getBodyLenght())).c_str(), text_pos_x, text_pos_y + 60, 40, WHITE);
    }

    EndDrawing();
}
