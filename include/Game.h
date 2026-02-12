#pragma once
#include "Board.h"
#include "Food.h"
#include "raylib.h"

class Game{
    private: 
        Color myWhite = {220, 220, 220, 80};
        bool running = true;
        int posX = 40;
        int posY = 40;
        int randX = 0;
        int randY = 0;
        Board board;
        Food food;
    public:
        void run();
};