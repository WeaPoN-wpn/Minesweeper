# Minesweeper
A simple minesweeper game in C++.

 ## General rules
 * Enter the coordinate of a square, the square will be turned over, and the number in the square indicates how many mines there are in the 8 squares around it.   
 * The goal of the game is to find all the mines and turn over all the squares without mines. If there is a mine under the opened square, the game fails.  
 ## More in details
 #### General settings  
 * The width of the minefield is 9 and the length is 9  
* The number of mines is equal to 10  
 * 10 mines are placed in random squares  
* The coordinate is reached by entering the row (from 0 to 8) and column (from 0 to 8).

 #### Start the game
* Launch the game by entering ./minesweep
* Display "Game objective: Open all blocks without mines" and "Select operation:" in the first and second row
* Ask the player "Enter '0' for starting a game" or "Enter '1' for show the mine map of the most recent game"
* If the player enter '0', then a new mine map will be randomly generated. The play can continue to play (see the Main body of the game)


* Else if the player enter '1', the the mine map of the most recent game will be displayed.
* Then ask the player "Enter '0' for starting a new game" or "Enter '1' for quitting"
* If the player enter '0', then a new mine map will be randomly generated. The play can continue to play (see the Main body of the game)
* If the player enter '1', then he/she will quit the game

 #### Main body of the game
* Display the unopened mine map
* Display "Select operation:"
* Ask the player "Enter '0' for marking a block" or "Enter '1' for opening a block" or "Enter '2' for quitting"
* If the player enter '0', then display "Please enter coordinates (row, column)" and asks the player to enter the coordinate
* After entering the coordinate, the new minefield map will be displayed again (the marked square is displayed with "*")


* Else if the player enter '1', then display "Please enter coordinates (row, column)" and asks the player to enter coordinates
* After entering the coordinate, the square will be opened by following the rules:
* If there is a mine in the square of the input coordinates, the game will determine that you have met the conditions for failure (see End the game)
* If the square with the entered coordinates has no mines, the new mine map will be displayed again (the opened square shows how many squares have mines around; if there are 0 squares around with mines, a space is displayed)
* If the square that the player opens has no mines, all surrounding squares without mines will be automatically opened.


* Else if the player enter '2', then he/she will quit the game

 #### End the game
* After each round the player marks or opens a square, the game will determine whether or not he/she has met the game-winning condition:
* the number of unopened squares is equal to 10
* If it is equal to 10, it will display "Sweep all the bombs! Congratulations!"


* If, during one round, the player opens a block with mine
* Then the mine map will be displayed (all blocks containing mine will be shown by "X") followed by "Sorry you step on a bomb. Game Over!"

 #### Meeting requirement
* Generation of random game sets or events. 10 mines are randomly placed in 10 squares.
* Data structures for storing game status. Every time the player turns over or marks a square, the latest minefield map is displayed.
* Dynamic memory management. There are two dynamic arrays in the program (xpos[] and ypos[]) for storing the mines' coordinates.
* File input/output. The mine map is automatically saved in a file called gamedata.txt after the player "Enter '0' for starting a new game". Player can also check the mine map of the most recent game by "Enter '1' for show the mine map of the most recent game".
* Program codes in multiple files. Using makefile. First, compile the source files which contain all functions used in the program into intermediate code files. Then a large number of object files are synthesized into executable files.
* Proper indentation and naming styles. The function section is separate from the main section. Use easy-to-understand names for functions.
* In-code documentation. At the end of each function is a note on the purpose and action of the function.
