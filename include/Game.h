#pragma once
#include "Snake.h"
#include "raylib.h"


class Game{
    private: 
        struct Board{
            int height = 720;
            int width = 1120;
            int bSize = 40;
            Color myWhite = {220, 220, 220, 80};
            void render();
        };
        struct Food{
            int posX;
            int posY;
            int fSize = 40;
            Color myFood = {255, 90, 90, 255};
            void setFPos();
            void spawnFood();
        };
        
        Color myGreen = {80, 200, 120, 255};
        bool running = true;
        char tempDir = 'X';
        char dir = 'X';
        int size = 40;
        int speed = 5;
        int timer = 0;
        int highScore = 0;
        int score = 0;
        bool isEat = false;
        Board board;
        Food food;
        Snake snake;
    public:
        void run();
        char getDir();
        void drawSnake();
        void restart();
        bool isGameOver();
        bool isCollision();
        void loadHighScore();
        void setScore();
};