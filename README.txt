-------------------------------Simple Console Lane Game----------------------------------

Description:

This is a simple console-based lane game in C where the player controls a car to avoid falling obstacles. The game runs in the Windows console and uses keyboard input for control.

How to Play:

Use the LEFT (←) and RIGHT (→) arrow keys to move the car between three lanes.

Avoid the obstacles that fall from the top.

The game ends if the car collides with an obstacle.

Game Logic:

Initialization-

Set console color and initialize random seed.

Player starts in the middle lane (x = 1).

The first obstacle lane is randomly chosen.

Main Game Loop-

Input: Check if arrow keys are pressed and move the car left or right.

Draw:

Clear the screen quickly to reduce flicker.

Draw lanes, obstacle, and player car in their positions.

Collision Check: If the obstacle reaches the player's row and the lane matches the player, the game ends.

Obstacle Movement: Obstacles move one step down each loop iteration. Once an obstacle reaches the bottom, a new one is generated in a random lane.

Game Speed-

The loop pauses for 120 ms between iterations to control game speed.

Implementation Notes:

Uses windows.h and conio.h for console manipulation and keyboard input.

Uses rand() for random obstacle positions.

clear_screen_fast() updates the console efficiently to prevent flickering.
