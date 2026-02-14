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
void Snake::move(char dir, bool isEat){
    
    switch(dir){
        case 'W':
            body.insert(body.begin(), {getSnakeX(0), getSnakeY(0) - size});
            if(!isEat){
                body.pop_back();
            }
            break;
        case 'A':
            body.insert(body.begin(), {getSnakeX(0) - size, getSnakeY(0)});
            if(!isEat){
                body.pop_back();
            }
            break;
        case 'S':
            body.insert(body.begin(), {getSnakeX(0), getSnakeY(0) + size});
            if(!isEat){
                body.pop_back();
            }
            break;
        case 'D':
            body.insert(body.begin(), {getSnakeX(0) + size, getSnakeY(0)});
            if(!isEat){
                body.pop_back();
            }
            break;
        default :
            break;
    }
}

void Snake::deleteS(){
    body.clear();
    body = {{200, 200}};
}