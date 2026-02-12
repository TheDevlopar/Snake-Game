#pragma once
#include <vector>

struct Position;
class Board{
    private:
        int height = 720;
        int width = 1120;
        int rectH = 40;
        int rectW = 40;
    public:
        int getRectH();
        int getRectW();
        int getH();
        int getW();
};