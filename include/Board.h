#pragma once
#include <vector>

struct Position;
class Board{
    private:
        int height = 800;
        int width = 1200;
        int rectH = 40;
        int rectW = 40;
    public:
        int getRectH();
        int getRectW();
        int getH();
        int getW();
};