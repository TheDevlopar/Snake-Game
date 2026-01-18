#include "Board.h"
#include <iostream>
#include "Game.h"
#include "snake.h"
#include "food.h"
#include <vector>
void Board::drawBoard(const std::vector<Position>&body, int Fx, int Fy, int score){

    for(int i = 0; i < width; i++){
        std::cout << ".";
    }
    std::cout << '\n';
    for(int i = 0; i < height; i++){
        std::cout << ".";

        for(int j = 0; j < width - 1; j++){
            bool printed = false;
            for(int k = 0; k < body.size(); k++){
                if(j == body[k].x && i == body[k].y){
                    std::cout << "O";
                    printed = true;
                    break;
                }
            }
            if(!printed && j == Fx && i == Fy){
                std::cout << "o";
                printed = true;
            }
            if(!printed){
                std::cout << " ";
            }
        }
        std::cout << ".\n";
    }
    for(int i = 0; i < width; i++){
        std::cout << ".";
    }
    std::cout << '\n';
    std::cout << "Score : " << score;
}

