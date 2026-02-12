#include "Snake.h"

int Snake::getSnakeX(){
    return body[0].x;
}
int Snake::getSnakeY(){
    return body[0].y;
}
void Snake::move(char dir){
    bodyX = body[0].x;
    bodyY = body[0].y;
    switch(dir){
        case 'W':
            bodyY -= 40;
            body.insert(body.begin(), {bodyX, bodyY});
            body.pop_back();
            break;
        case 'A':
            bodyX -= 40;
            body.insert(body.begin(), {bodyX, bodyY});
            body.pop_back();
            break;
        case 'S':
            bodyY += 40;
            body.insert(body.begin(), {bodyX, bodyY});
            body.pop_back();
            break;
        case 'D':
            bodyX += 40;
            body.insert(body.begin(), {bodyX, bodyY});
            body.pop_back();
            break;
        default :
            break;
    }
}