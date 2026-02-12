#include "../include/Game.h"
#include <iostream>
#include "raylib.h"

void Game::run(){
    InitWindow(board.getW(), board.getH(), "MyGame");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        while(running){
            DrawRectangleLines(posX, posY, board.getRectW(), board.getRectH(), WHITE);
            if(posY < board.getH()){
                posY += 40;
            }
            else if(posY == board.getH() && posX != board.getW()){
                posY = 0;
                posX += 40;
            }
            else if(posY == board.getH() && posX == board.getW()){
                running = false;
            }
        }
        EndDrawing();
    }
    CloseWindow();
}