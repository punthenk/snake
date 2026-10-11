#include "Apple.h"
#include "raylib.h"

Apple::Apple(Position init_pos) : pos_(init_pos) { }

void Apple::draw() {
    DrawRectangle(
        pos_.row_ * cell_size_ + 1,
        pos_.column_ * cell_size_ + 1,
        cell_size_ - 1,
        cell_size_ - 1,
        RED
    );
}

Position Apple::getPos() {
    return pos_;
}

void Apple::setIsEaten() {
    is_eaten_ = true;
}

bool Apple::isEaten() {
    return is_eaten_;
}
