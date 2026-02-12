#include "Food.h"

int Food::getX(int randX){
    posX = randX * 40;
    return posX;
}
int Food::getY(int randY){
    posY = randY * 40;
    return posY;
}