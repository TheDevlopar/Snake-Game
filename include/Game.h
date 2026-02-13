#pragma once
#include "Board.h"
#include "Food.h"
#include "Snake.h"
#include "raylib.h"

class Game{
    private: 
        Color myWhite = {220, 220, 220, 80};
        bool running = true;
        int posX = 40;
        int posY = 40;
        int randX = 0;
        int randY = 0;
        char tempDir = 'X';
        char dir = 'X';
        Board board;
        Food food;
        Snake snake;
    public:
        void run();
        void render(Board &board);
        char getDir();
};