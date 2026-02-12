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

void Game::run(){
    InitWindow(1200, 800, "MyGame");
    SetTargetFPS(60);


    //Get random numbers for food
    randX = GetRandomValue(1, 28);
    randY = GetRandomValue(1, 18);

    while(!WindowShouldClose()){
        //ClearBackground(BLACK);
        BeginDrawing();
        ClearBackground(BLACK);
        //Draw Board
        while(running){
            DrawRectangleLines(posX, posY, board.getRectW(), board.getRectH(), myWhite);
            if(posY < board.getH()){
                posY += 40;
            }
            else if(posY == board.getH() && posX != board.getW()){
                posY = 40;
                posX += 40;
            }
            else if(posY == board.getH() && posX == board.getW()){
                running = false;
                posX = 40;
                posY = 40;
            }
        }
        //Food
        DrawRectangle(food.getX(randX), food.getY(randY), board.getRectW(), board.getRectH(), BLUE);
        //Snake draw
        DrawRectangle(snake.getSnakeX(), snake.getSnakeY(), 40, 40, RED);
        //Input  
        tempDir = getDir();
        if(tempDir != dir && tempDir != 'X'){
            dir = tempDir;
        }
        snake.move(dir);
        running = true;
        EndDrawing();
    }
    CloseWindow();
}