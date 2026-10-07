#include "Game.h"
#include "raylib.h"

Game::Game(int targetFps) :
    TARGET_FPS(targetFps)
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
}

void Game::draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("HELLO", 20, 20, 20, WHITE);

    EndDrawing();
}
