#pragma once
#include <vector>

struct Position;
class Board{
    private:
        int height = 35;
        int width = 35;
    public:
        void drawBoard(const std::vector<Position>& body, int Fx, int Fy, int score);
};