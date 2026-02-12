#include "../include/Game.h"
#include <iostream>
#include "raylib.h"

void Game::run(){
    InitWindow(1200, 800, "MyGame");
    SetTargetFPS(60);

    randX = GetRandomValue(1, 28);
    randY = GetRandomValue(1, 18);
    while(!WindowShouldClose()){
        
        BeginDrawing();
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
            }
        }

        //Food
        DrawRectangle(food.getX(randX), food.getY(randY), board.getRectW(), board.getRectH(), RED);
        EndDrawing();
    }
    CloseWindow();
}