#pragma once
#include <iostream>
#include <vector>
struct Position
        {
            int x;
            int y;
        };

class Snake{
    private:
        int bodyX = 0;
        int bodyY = 0;
        int speed = 1;
    public:
    bool eat = false;
    std::vector<Position> body ={{9, 9}};
        void move(char dir, bool eat);
        void grow();
};
