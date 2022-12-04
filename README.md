# HKU-gold-miner
COMP2113 Group Project

# Group Member:
* Guo Xiaole 3035771660
* Jian Tianyi 3035637668
* Kong Xinman 3035772690
* Ma Qiyao 3035771153
* Wang Yimeng 3035845485

# Game Rule Description
* The player of this game plays as a gold miner in a 10*10 table. Firstly, there are two mode to choose from: 1-Normal and 2-Adventure. In the normal mode, you need to win the most amount of gold you can within 5 chances in the normal mode. In the adventure mode, your goal is to win as much gold as you can until all the gold are mined or you mine the bomb. Secondly, there are 3 difficulties to choose from: 1-easy, 2-intermediate, 3-hard. In each unit of the table, you have 3 possibilities: gold with different scores (1~30), bomb or nothing. 
* Luckily, this is not a game totally for guessing and opportunity. We give you an instruction whenever you choose a unit. In the instruction, there will be two numbers in a row. The first number is the total amount of gold in the 3*3 table around and exclude the selected coordinates. The second number is the number of bombs in the 3*3 table around the selected coordinates.
* After one round of the game, you will be able to choose whether playing again or not. In the end of the game, your best score and the top three players will be shown.
* If you exit before finish your goal, we have recorded the game status for you. When you enter later, you can choose to play the loading game by answering "Yes" to the question on whether to continue last play.

# Coding Elements:
* Generation of random game sets or events: In initialiazation.cpp, we use rand function to generate the bomb and gold.
* Data structures for storing game status: In the main.cpp, we store the status of each round if it is not finished by outputting the status to BOARD.txt, MODE.txt, coordinate.txt and MAP.txt.
* Dynamic memory management: In main.cpp, we use dynamic memory to calculate the total number of the golds and bombs.
* File input/output: In main.cpp, we use fin and fout to store the best scores in file SCORE.txt and to store the game status in files.
* Program codes in multiple files: Our codes are in initialization.cpp, instruction.cpp, routine.cpp and main.cpp.
* Proper indentation and naming styles: The variables are named according to their usage. The indentation is readable.
* In-code documentation: We have comments for structs defination and functions.

# Non-standard C/C++ Libraries:
NA

# Compilation and execution instructions:
Download all the files we submitted to the Github and store them in a directory. In the directory of this project, type "make main" to compile. Then type "./main" to execute. Then, you will enter the game and just follow the instructions in the game to play it.

