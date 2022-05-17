# Game 2048

Game 2048 for unix terminals.

## Installation

**for simple unix**
+ git clone https://github.com/pbalykov/game-2048.git
  (the file is being installed)
+ cd game-2048 (go to the folder)
+ make or make run
 (the first method collects, the second collects and launches)
+ ./Game-2048
  (starting the game)

**if you have nixos**
+ git clone https://github.com/pbalykov/game-2048.git
  (the file is being installed)
+ cd game-2048 (go to the folder)
+ nix-shell -p "import ./config.nix {}"
  (building a program)
+ Game-2048
  (starting the game)


## Controls

+ W, w and (up arrow) -> UP
+ S, s and (down arrow) -> DOWN
+ A, a and (left arrow) -> LEFT
+ D, d and (right arrow) -> RIGHT
+ q -> exit


## About the code

The code is written in C. The headers folder contains header files, controls are executed using break and select. 
Also, the field is made dynamically, although you can do it for every taste.
