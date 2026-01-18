#include "snake.h"
#include <iostream>

void Snake::move(char dir, bool eat){
    bodyX = body[0].x;
    bodyY = body[0].y;
    switch(dir){
        case 'w':
            body.insert(body.begin(), {bodyX, bodyY - speed});
            if(!eat){
                body.pop_back();
            }
            break;
        case 's':
            body.insert(body.begin(), {bodyX, bodyY + speed});
            if(!eat){
                body.pop_back();
            }
            break;
        case 'a':
            body.insert(body.begin(), {bodyX - speed, bodyY});
            if(!eat){
                body.pop_back();
            }
            break;
        case 'd':
            body.insert(body.begin(), {bodyX + speed, bodyY});
            if(!eat){
                body.pop_back();
            }
            break;
        default:
            break;
    }
}
