#include "Snake.h"

int Snake::getSnakeX(int i){
    return body[i].x;
}
int Snake::getSnakeY(int i){
    return body[i].y;
}
int Snake::getSnakeLen(){
    return body.size();
}
void Snake::setEat(bool isEat){
    eat = isEat;
}
void Snake::move(char dir){
    bodyX = body[0].x;
    bodyY = body[0].y;
    switch(dir){
        case 'W':
            bodyY -= 40;
            body.insert(body.begin(), {bodyX, bodyY});
            if(eat == false){
                body.pop_back();
            }
            break;
        case 'A':
            bodyX -= 40;
            body.insert(body.begin(), {bodyX, bodyY});
            if(eat == false){
                body.pop_back();
            }
            break;
        case 'S':
            bodyY += 40;
            body.insert(body.begin(), {bodyX, bodyY});
            if(eat == false){
                body.pop_back();
            }
            break;
        case 'D':
            bodyX += 40;
            body.insert(body.begin(), {bodyX, bodyY});
            if(eat == false){
                body.pop_back();
            }
            break;
        default :
            break;
    }
}