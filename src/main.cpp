#include <raylib.h>
#include "core/Game.h"

#define WIDTH 600
#define HEIGHT 600
#define TARGET_FPS 60

int main (int argc, char *argv[]) {
    InitWindow(WIDTH, HEIGHT, "Snake");

    while (!WindowShouldClose()) {
        Game game(TARGET_FPS);
        game.run();
    }

    CloseWindow();
    return 0;
}
