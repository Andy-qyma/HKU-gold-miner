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
* After one round of the game, you will be able to choose whether playing again or not. And the best score of each player will be recorded. In the end of the game, your best score and the top three players will be shown.

# Coding Elements:
* Generation of random game sets or events: In initialiazation.cpp, we use rand function to generate the bomb and gold.
* Data structures for storing game status: In initialization.cpp and main.cpp, we use arrays to store the status of the table, golds, bombs and the chosen units.
* Dynamic memory management: 
* File input/output:
* Program codes in multiple files:
* Proper indentation and naming styles:
* In-code documentation: 
