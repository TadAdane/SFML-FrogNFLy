# 🕹Labyrinth Game

## 🖥Game Using SFML 

 It is a simple game in which a character is moved using the arrow keys on the keyboard. The game window has a grass background, and there are walls surrounding the game area.

The code uses the `SFML library` for graphics and window management. The game logic is contained within the `moveInDirection` function, which takes in the elapsed time since the last frame, the pressed key, the player sprite, the window, and a vector of wall sprites. The function moves the player sprite in the direction specified by the pressed key, with a fixed speed. The function also checks for collisions between the player sprite and the wall sprites. If a collision is detected, the player sprite is moved back to a position where it is not colliding with any wall sprite.

The main function creates the game window, loads the textures for the `grass, wall, and guy` sprites, and creates the wall sprites. The game loop repeatedly draws the grass and wall sprites, and updates the player sprite based on the user input and collision detection.

Must add the png and jpg files in the build folder of QT.


### 🎞The video of  game :


[![Alt Text](https://img.youtube.com/vi/dcyWkqTrcb4/0.jpg)](https://www.youtube.com/watch?v=dcyWkqTrcb4)

#### YouTube link : https://www.youtube.com/watch?v=dcyWkqTrcb4.

Author : *Tadiwos Andargie*
