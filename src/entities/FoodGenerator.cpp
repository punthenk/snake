#include "FoodGenerator.h"
#include "entities/Apple.h"

FoodGenerator::FoodGenerator() = default;

void FoodGenerator::update() {
    if (current_apple_ != nullptr && current_apple_->isEaten()) {
        delete current_apple_;
        current_apple_ = generateFood();
    } else if (current_apple_ == nullptr) {
        current_apple_ = generateFood();
    }
}

void FoodGenerator::reset() {
    if (current_apple_ != nullptr) {
        delete current_apple_;
        current_apple_ = generateFood();
    } else {
        current_apple_ = generateFood();
    }
}

Apple* FoodGenerator::generateFood() {
    int x = dist20_(rng_);
    int y = dist20_(rng_);

    return new Apple(Position{x, y});
}
