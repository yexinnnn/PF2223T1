# Part 2

## Video Demo

https://youtu.be/f2nUat_Jx0c

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
10. Create Alien character in the middle of the game board
11. Move Alien with ('^,v, <,>) control and able to +20 attack points to the alien (for each arrow)  
12. If health care(h) encouter by alien, life attribute will +20
13. If alien encounter pod object,it will attack nearest zombies with damage of 10
14. Alien will attack zombie if it meet zombie at its turn
15. Ask user want to play again or not when Alien win
16. Display trail after Alien encounter with the any object
17. Trail reset everytime alien end its turn and it will randomly generate game object
18. If alien encounter rock, rock will automatically generate any object
19. Zombie created
20. Active zombie & alien turn
21. If zombie successfully attack alien, it will display alien's life in the next step
22. Changing game board's arrow (^,v,<,>)
23. Save file
24. Load File
25. Quit Game


## Additional Features

1. User's input are accepted even using capital letter or small leter
2. User are required to enter correct input in order to change game board's arrow
3. User are required to enter correct input in commands section

## Contributions

### LIM YE XIN

1. Display default game settings
2. Display and change board settings
3. Randomly generate game board
4. Create Alien character and display it at the middle of the game board
5. Alien's movement (up/down/left/right) including +20 alien's attack when encounter arrow
6. Alien encounter rock and health object
7. Trail reset everytime when Alien end its tuurn
8. Alien's attack convert back to 0 in each turn
9. Rock object stops alien from moving and it will discover a hidden item
10. Alien's life +20 when encouner health object
11. Alien/Zombie turn
12. Zombie move
13. Zombie attack
14. Change game board's arrow


### TER ZHENG BIN

1. Alien and Zombie attribute
2. Command ("help") to display game's instruction
3. Alien encounter pod object
4. Pod object finds the neareast zombie to attack
5. Alien encounter zombie
6. Create Zombie character
7. Differentiate each zombies
8. Ask user want to play again or not after alien defeated zombie


### LAI JIAN SENG

1. Implement all game objects.
2. Help to display Alien and Zombie attribute
3. Randomly generate objects inside the game board
4. helping in change game board's arrow
5. Save & load game
6. Quit game

## Problems Encountered & Solutions

1. Problem  : Game board change everytime when user change default game setting
   Solution : Deleted random generate object which accidentally added

2. Problem  : Program stopped whenever user enter the wrong input
   Solution : Force user to enter the correct input

3. Problem  : Can't distingush the zombie and show the attribute
   Solution : Make a for loop and need to change the number into a char form

4. Problem  : When Aliean hit the zombie, zombie will missing
   Solution : Don't replace it with putting a zombie[i] inside because it is there already

5. Problem  : function repeat_game can't go into the condition
   Solution : inside the condition from "" change into ''because of string

