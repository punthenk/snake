#include <raylib.h>
#include "core/Game.h"

#define TARGET_FPS 60

int main (int argc, char *argv[]) {
    InitWindow(Game::WIDTH, Game::HEIGHT, "Snake");

    while (!WindowShouldClose()) {
        Game game(TARGET_FPS);
        game.run();
    }

    CloseWindow();
    return 0;
}
