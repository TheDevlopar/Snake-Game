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
    for(int i = 40; i < board.height; i += 40){
        for(int j = 40; j < board.width; j += 40){
            DrawRectangleLines(j, i, board.rectW, board.rectH, myWhite);
        }
    }
}
void Game::spawnFood(){
    DrawRectangle(fPosX, fPosY, 40, 40, myFood);
    DrawRectangleLines(fPosX, fPosY, 40, 40, BLACK);
}
void Game::drawSnake(Snake &snake){
    for(int i = 0; i < snake.getSnakeLen(); i++){
        DrawRectangle(snake.getSnakeX(i), snake.getSnakeY(i), 40, 40, mySnake);
        DrawRectangleLines(snake.getSnakeX(i), snake.getSnakeY(i), 40, 40, BLACK);
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
    if(snake.getSnakeX(0) >= board.width || snake.getSnakeX(0) <= 0 || snake.getSnakeY(0) >= board.height || snake.getSnakeY(0) <= 0){
        return true;
    }
    else{
        return false;
    }
}
bool Game::isCollision(){
    for(int i = 1; i < snake.getSnakeLen(); i++){
        if(snake.getSnakeX(0) == snake.getSnakeX(i) && snake.getSnakeY(0) == snake.getSnakeY(i)){
            return true;
        }
    }
    return false;
}
void Game::run(){
    InitWindow(1160, 760, "MyGame");
    SetTargetFPS(60);


    //Get random numbers for food
    
    
    setFX();
    setFY();
    while(!WindowShouldClose()){
        if(running){
            BeginDrawing();
            ClearBackground(BLACK);

            //Frame counter for snake movement 
            timer++;

            //Draw Board
            render(board);

            //Food
            spawnFood();
            
            //Snake draw
            drawSnake(snake);

            //Input  
            tempDir = getDir();
            if(tempDir != dir && tempDir != 'X'){
                dir = tempDir;
            }

            //I don't understand this part much but it has something to do with keeping everything consistent with the movement frame i guess.
            if(timer == speed){
                if(snake.getSnakeX(0) == fPosX && snake.getSnakeY(0) == fPosY){
                    setFX();
                    setFY();
                    isEat = true;
                }
                else{
                    isEat = false;
                }
                snake.move(dir, isEat);
                if(isGameOver() == true || isCollision() == true){
                    CloseWindow();
                }
                timer = 0;
            }

            EndDrawing();
            
        }
    }
    CloseWindow();
}