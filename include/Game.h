#pragma once
#include "Board.h"

class Game{
    private: 
        bool running = true;
        int posX = 0;
        int posY = 0;
        Board board;
    public:
        void run();
};