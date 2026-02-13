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
        render(board);
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