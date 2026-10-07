#include <raylib.h>
#include "core/Game.h"

#define WIDTH 900
#define HEIGHT 600
#define TARGET_FPS 60

int main (int argc, char *argv[]) {
    InitWindow(WIDTH, HEIGHT, "Lutjegast racer");

    while (!WindowShouldClose()) {
        Game game(TARGET_FPS);
        game.run();
    }

    CloseWindow();
    return 0;
}
