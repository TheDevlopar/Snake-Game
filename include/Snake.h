#pragma once
#include <vector>



class Snake{
    private: 
        struct Position{
            int x;
            int y;
        };
        std::vector<Position> body = {{200, 200}};
        int bodyX = 0;
        int bodyY = 0;
        int size = 40;
        bool eat = false;
    public:
        
        int getSnakeX(int i);
        int getSnakeY(int i);
        void move(char dir);
        int getSnakeLen();
        void setEat(bool isEat);
};
