#include <iostream>
#include "Game.h"
#include <ctime>
#include "raylib.h"


int main(){
    bool running = true;
    srand(time(0));
    
    Game game;
    game.run();
    while(running){
        if(game.restart() == true){
            game.run();
        }
        else{
            running = false;
            return 0;
        }
    }
}
