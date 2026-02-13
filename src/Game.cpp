#include "../include/Game.h"
#include <iostream>
#include "raylib.h"

char Game::getDir(){
    if(IsKeyPressed(KEY_W) && dir != 'S'){
        return 'W';
    }
    else if(IsKeyPressed(KEY_A) && dir != 'D'){
        return 'A';
    }
    else if(IsKeyPressed(KEY_S) && dir != 'W'){
        return 'S';
    }
    else if(IsKeyPressed(KEY_D) && dir != 'A'){
        return 'D';
    }
    else{
        return 'X';
    }
}
void Game::render(Board &board){
    for(int i = 40; i < board.getBH(); i += 40){
        for(int j = 40; j < board.getBW(); j += 40){
            DrawRectangleLines(j, i, board.getRectW(), board.getRectH(), myWhite);
        }
    }
}
void Game::spawnFood(){
    DrawRectangle(fPosX, fPosY, 40, 40, BLUE);
}
void Game::drawSnake(Snake &snake){
    for(int i = 0; i < snake.getSnakeLen(); i++){
        DrawRectangle(snake.getSnakeX(i), snake.getSnakeY(i), 40, 40, RED);
    }
}
void Game::setFX(){
    randX = GetRandomValue(1, 27);
    fPosX = food.getX(randX);
    
}
void Game::setFY(){
    randY = GetRandomValue(1, 17);
    fPosY = food.getX(randY);
}
bool Game::isGameOver(){
    if(snake.getSnakeX(0) >= board.getBW() || snake.getSnakeX(0) <= 0 || snake.getSnakeY(0) >= board.getBH() || snake.getSnakeY(0) <= 0){
        return true;
    }
    else{
        return false;
    }
}
void Game::run(){
    InitWindow(1160, 760, "MyGame");
    SetTargetFPS(60);


    //Get random numbers for food
    
    
    setFX();
    setFY();
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(BLACK);

        //Frame counter for snake movement 
        timer++;
        //Draw Board
        render(board);

        //Food
        spawnFood();
        while(snake.getSnakeX(0) == fPosX && snake.getSnakeY(0) == fPosY){
            setFX();
            setFY();
            snake.setEat(true);
        }
        

        //Snake draw
        drawSnake(snake);

        //Input  
        tempDir = getDir();
        if(tempDir != dir && tempDir != 'X'){
            dir = tempDir;
        }
        if(timer == speed){
            snake.move(dir);
            timer = 0;
        }
        snake.setEat(false);
        EndDrawing();
        if(isGameOver() == true){
            CloseWindow();
        }
    }
    CloseWindow();
}