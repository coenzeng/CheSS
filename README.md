# CheSS
Chess game built in C++ using OOP principles. 

![uml-1](https://user-images.githubusercontent.com/63679316/218340678-0a8b6128-87ff-4342-812f-c53f1b4d0bc7.png)

## Highlights: 
1. Inheritance structure for pieces and players, providing compartmentalization for different aspects of the game.
2. Allows player vs player, player vs computer, and computer vs computer.
3. Three different levels for the computer, with the highest level being able to detect capture moves and avoid capture.
2. Observer design pattern to update the terminal and graphical display. 
3. Smart pointers throughtout for automatic memory management. 
4. A setup mode, which allows the user to create their own starting position and play from there. 

## How to download on local:
1. Run `make`.
2. Make sure to have X11 forwarding enabled for the graphical window. 
3. Run the executable`./chess`. This will take in input until the end of file execution. 

## Setup Mode
1. Type in `setup` to enter setup mode. You may only enter setup mode if you're not in a game.
2. In setup mode, you start with an empty chess board and you place pieces as you wish.

## Game Mode
1. Type in `game human human` to enter a game.
2. Or type `game computer1` or `game computer2` to play against a computer.

See the test folder for example input. 
