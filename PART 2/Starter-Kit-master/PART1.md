# Part 1

## Video Demo

https://youtu.be/c9LYFJThtl0

## Minimum Requirements

### Completed

1. Game interface able to displayed when user enter the game
2. User able to see default game settings
3. User able to change or not to change the game settings
4. User able to change board settings (rows & columns with odd numbers)
5. User able to change or not to change the number of zombies
6. Alien & Zombie attributes able to displayed after enter the game
7. User able to see game's instruction after entering "help" 
8. Two-dimension game board able to displayed correctly 
9. Object inside the game board able to display randomly (health,pod,rock)

### To Do
1. Display Alien in the middle of the game board
2. Move Alien with ('^,v, <,>) control and able to +20 attack points to the alien (for each arrow)  
3. If health care(h) encouter by alien, life attribute will +20
4. If alien encounter pod object,it will attack nearest zombies with damage of 10
5. Display trail after Alien encounter with the any object
6. Set zombie at the place which far apart from the alien when randomly generate
7. If alien encounter rock, rock will automatically generate any object
8. If zombie successfully attack alien, it will display alien's life in the next step
9. If alien is dead, it will display the condition of the game
10. Function of Change arrow ( ^,v,<,>)
11. Save file
12. Quit Game
13. Load File


## Additional Features

Describe the additional features that has been implemented.

## Contributions

### LIM YE XIN

1. Display default game settings.
2. Display and change board settings
3. Randomly generate game board.


### TER ZHENG BIN

1. Alien and Zombie attribute
2. Command ("help") to display game's instruction

### LAI JIAN SENG

1. Implement all game objects.
2. Help to display Alien and Zombie attribute
3. Randomly generate objects inside the game board

## Problems Encountered & Solutions

1. Problem  : Display Alien and Zombie attribute 
   Solution : create a new class instead using the same class

2. Problem  : After entering the "help" and press Enter will quit from the program. Even Though we insert the command() function.
   Solution : Cancel the help class and just put it inside the command function
