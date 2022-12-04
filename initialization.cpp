//  initialization.cpp

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "initialization.h"
using namespace std;



void Initialboard(int board[10][10]){
    const int ROWS = 10;
    const int COLUMNS = 10;
    const int MINE = -1;

    for (int i =0; i < ROWS; i++){
      for (int j =0; j < COLUMNS; j++){
        board[i][j] = 0;
      }
    }
  }

//the function of setting gold
void Setgold(int board[10][10]){
  //set a random to avoid get the same random number using rand()
  srand((unsigned)time(NULL));
  // int gold is the score of the gold
  // int row column is the position to get the gold
  // using row1 column 1 as the index
    int row1, column1;
    int gold = 1;
    while (gold < 31){
      row1 = rand()%10;
      column1 = rand()%10;
      if (board[row1][column1] == 0){
        board[row1][column1] = gold;
        gold++;
      }
    }
  }

//the function of setting mine, number is the number of the mine, according to the mode
void Setmine(int board[10][10], int number){
  srand((unsigned)time(NULL));
  int row2, column2;

    while (number > 0){
      row2 = rand()%10;
      column2 = rand()%10;
      if (board[row2][column2] == 0){
        board[row2][column2] = -1;
        number--;
      }
    }
  }
