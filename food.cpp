#include "food.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


int Food::getX(){
    return x;
}
int Food::getY(){
    return y;
}
void Food::setPos(){
    x = ((rand() % 33) + 1);
    y = ((rand() % 33) + 1);
}