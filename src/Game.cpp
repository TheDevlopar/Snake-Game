#include "../include/Game.h"
#include <iostream>
#include "raylib.h"
#include <fstream>

void Game::loadHighScore(){
    std::ifstream file("highScore.txt");
    file >> highScore;
}

void Game::setScore(){
    std::ofstream file("highScore.txt");
    file << highScore;
}

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

void Game::Food::setFPos(){
    posX = GetRandomValue(1, 27) * fSize;
    posY = GetRandomValue(1, 17) * fSize;
}

void Game::Food::spawnFood(){
    DrawRectangle(posX, posY, fSize, fSize, myFood);
    DrawRectangleLines(posX, posY, fSize, fSize, BLACK);
}

void Game::Board::render(){
    for(int i = bSize; i < height; i += bSize){
        for(int j = bSize; j < width; j += bSize){
            DrawRectangleLines(j, i, bSize, bSize, myWhite);
        }
    }
}

void Game::drawSnake(){
    for(int i = 0; i < snake.getSnakeLen(); i++){
        DrawRectangle(snake.getSnakeX(i), snake.getSnakeY(i), size, size, myGreen);
        DrawRectangleLines(snake.getSnakeX(i), snake.getSnakeY(i), size, size, BLACK);
    }
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

void Game::restart(){
    food.setFPos();
    snake.deleteS();
    timer = 0;
    dir = 'X';
    running = true;
    score = 0;
}

void Game::run(){
    InitWindow(1160, 760, "MyGame");
    SetTargetFPS(60);

    //Set coordinates for food
    food.setFPos();
    while(!WindowShouldClose()){
        BeginDrawing();
        if(running){
            ClearBackground(BLACK);

            loadHighScore();
            DrawText(std::to_string(score).c_str(), 560, 20, 20, WHITE);
            //Frame counter for snake movement 
            timer++;

            //Draw Board
            board.render();

            //Food
            food.spawnFood();

            //Input
            tempDir = getDir();
            if(tempDir != dir && tempDir != 'X'){
                dir = tempDir;
            }
            
            //Snake draw
            drawSnake();

            //I don't understand this part very well but it has something to do with keeping everything consistent with the movement frame i guess.
            if(timer == speed){  
                
                if(snake.getSnakeX(0) == food.posX && snake.getSnakeY(0) == food.posY){
                    food.setFPos();
                    isEat = true;
                    score++;
                }
                else{
                    isEat = false;
                }
                snake.move(dir, isEat);
                if(isGameOver() || isCollision()){
                    running = false;
                    if(score > highScore){
                        highScore = score;
                        setScore();
                    }
                }
                timer = 0;
            }
        }
        else{
            ClearBackground(BLACK);
            DrawText((" \n HighScore : " + std::to_string(highScore)).c_str(), 360, 560, 20, WHITE);
            DrawText(" \n Game Over \n Press Enter to play again \n Press ESC to exit", 360, 600, 20, WHITE);
            if(IsKeyPressed(KEY_ENTER)){
                restart();
            }
        }
        
        EndDrawing();
    }
    CloseWindow();
}