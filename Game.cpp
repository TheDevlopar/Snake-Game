#include <iostream>
#include "Game.h"
#include <conio.h>
#include <windows.h>
char Game::getDir(){
    char inp;
    if(_kbhit()){
        switch(_getch()){
            case 'w':
                inp = 'w';
                return inp;
            case 's':
                inp = 's';
                return inp;
            case 'a':
                inp = 'a';
                return inp;
            case 'd':
                inp = 'd';
                return inp;
            default:
                inp = 'x';
                return inp;
        }
    }
}

bool Game::gameOver(){
    if(snake.body[0].x <= -1 || snake.body[0].x >= 35 || snake.body[0].y <= -1 || snake.body[0].y >= 35){
        return true;
    }
    for(int i = 1; i < snake.body.size(); i++){
        if(snake.body[i].x == snake.body[0].x && snake.body[i].y == snake.body[0].y){
            return true;
        }
    }
    return false;
}
bool Game::restart(){
    bool playAgain;
    do{
        std::cout << '\n';
        std::cout << "Game Over. '\n' Enter '1' to Play again '\n' Enter '0' to Exit. ";
        std::cin >> playAgain;
    } while(playAgain != 0 && playAgain != 1);

    if(playAgain){
        while(snake.body.size() > 1){
            snake.body.pop_back();
        }
        snake.body[0].x = 0;
        snake.body[0].y = 0;
        dir = 'x';
        running = true;
        score = 0;
        return true;
    }
    else{
        return false;
    }
}

void Game::run(){
    food.setPos();
    int Fx = 0;
    int Fy = 0;
    while(running){
        printf("\033c");
        //Food section
        Fx = food.getX();
        Fy = food.getY();
        if(Fx == snake.body[0].x && Fy == snake.body[0].y){
            food.setPos();
            snake.eat = true;
            score++;
        } 
        // Input section
        char inp = getDir();
        if(inp == 'w' && dir != 's' || inp == 'a' && dir != 'd' || inp == 's' && dir != 'w' || inp == 'd' && dir != 'a'){
            dir = inp;
        }
        snake.move(dir, snake.eat);
        board.drawBoard(snake.body, Fx, Fy, score);
        snake.eat = false;  

        if(gameOver() == true){
            running = false;
            break;
        }
        Sleep(30);
    }
}
 