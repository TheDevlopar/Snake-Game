# Terminal snake game (C++)

A terminal-based Snake game written in C++ using object-oriented design.
The game runs entirely in the console and implements movement, growth,
self-collision, restart logic, and score handling.

## Features
- Terminal-based rendering
- Snake movement using vectors
- Food generation and growth logic
- Self collision and wall collision detection
- Restart functionality

## How to Run
1. Clone the Repo
2. Compile using c++ compiler (g++)
3. Run the executable in the terminal 

Example: 
``` bash
g++ *.cpp -o snake
./snake
```

### Controls
Example: 
- W -> Move Up
- A -> Move Left
- S -> Move Down
- D -> Move Right
- 1 -> Restart after game over
- 0 -> Exit

## Design Overview
 - `Game` handles the main game loop, input, and game state
 - `Snake` handles movement, body and growth
 - `Board` handles only rendering
 - `Food` handles food generation

 ## Future Improvements
 - Save high scores using file I/O
 - Add difficulty levels
 - Refactor input handling for other operating systems