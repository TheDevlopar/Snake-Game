# Snake Game (C++ / Raylib)

A classic Snake game built in C++ using Raylib and CMake.
This project was created to learn real-time game loops, rendering, and practical multi-file C++ project structure.

## Features
- Real-time rendering using Raylib
- Grid-based snake movement
- Food spawning and growth logic
- Self-collision and wall collision detection
- Game over screen with restart functionality

## How to Run
1. Clone the Repo
2. Build using CMake
3. Run the executable

## Example: 
``` 
mkdir build
cd build
cmake ..
make
./Snake
```

### Controls
Example: 
- W -> Move Up
- A -> Move Left
- S -> Move Down
- D -> Move Right
- Enter -> Restart after game over
- ESC -> Exit

## Design Overview
 - `Game` handles the main game loop, rendering, input, and game state
 - `Snake` handles movement, body management, and growth logic

 ## Future Improvements
 -  Add score display and high score saving
 -  Add sound effects and background music
 -  Add difficulty levels
 -  Add start menu and UI polish