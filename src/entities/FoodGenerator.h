#pragma once

#include "Apple.h"
#include <random>

class FoodGenerator {
public:
    FoodGenerator();
    void update();
    Apple* current_apple_ = nullptr;

private:
    Apple* generateFood();

    std::random_device rand_dev_;
    std::mt19937 rng_{rand_dev_()};
    std::uniform_int_distribution<int> dist20_{0, 19};

};    
