#pragma once
#include <vector>

class Snake{
    private: 
        struct Position{
            int x;
            int y;
        };
        std::vector<Position> body = {{200, 200}};
        int size = 40;
    public:
        
        int getSnakeX(int i);
        int getSnakeY(int i);
        void move(char dir, bool isEat);
        void deleteS();
        int getSnakeLen();
};
