#pragma once
#include "board.h"
#include "snake.h"
#include "food.h"

class Game{
    private:
        Board board;
        Snake snake;
        Food food;
        bool running = true;
        char dir = 'x';
        int score = 0;
    public:
        void run();
        char getDir();
        bool gameOver();
        bool restart();
};