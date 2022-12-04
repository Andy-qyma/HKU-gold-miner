//
//  routine.cpp
#include <iostream>
#include <fstream>
#include <iomanip>

#include "routine.h"
using namespace std;

//This function is to deal with each time the player choose the coordinates and give the instructions
void routine(Instruction *ins, int board[ROWS][COLUMNS], int map[ROWS][COLUMNS], int row, int column, int chance, int &score){
  cout<<"You have selected the coordinates: "<< row+1 <<" "<< column+1 <<endl;
  map[row][column] = board[row][column];
  cout<<"This the result of your choice."<<endl;
  for (int i =0; i < ROWS; i++){
    for (int j =0; j < (COLUMNS-1); j++){
      cout<<map[i][j]<<setw(3);
    }
    cout<<map[i][COLUMNS-1]<<endl;
  }
    //It is used to store the historical map.
    ofstream foutmap;
    foutmap.open("MAP.txt",ios::app);
    fstream filea("MAP.txt", ios::out);
    for (int i =0; i < ROWS; i++){
      for (int j =0; j < COLUMNS; j++){
        foutmap<< map[i][j]<<" ";
      }
        foutmap << endl;
    }
    foutmap.close();

  if (board[row][column] == -1){
    cout<<"You mine a bomb. Game over."<<endl;
  }
  
  if (board[row][column] >= 0){
    cout<<"The gold you win is "<<board[row][column]<<endl;
    int sum1=0, sum2=0;
    //sum1 is the sum of points around
    //sum2 is the sum of bombs around
    if ((row == 0) and (column == 0)){
      if (board[1][0] == -1)
        sum2+=1;
      if (board[1][1] == -1)
        sum2+=1;
      if (board[0][1] == -1)
        sum2+=1;
      if (board[1][0] > 0)
        sum1 = sum1 + board[1][0];
      if (board[1][1] > 0)
        sum1 = sum1 + board[1][1];
      if (board[0][1] > 0)
        sum1 = sum1 + board[0][1];
    }

    if ((row == 0) and (column == 9)){
      if (board[0][8] == -1)
        sum2+=1;
      if (board[1][9] == -1)
        sum2+=1;
      if (board[1][8] == -1)
        sum2+=1;
      if (board[0][8] > 0)
        sum1 = sum1 + board[0][8];
      if (board[1][9] > 0)
        sum1 = sum1 + board[1][9];
      if (board[1][8] > 0)
        sum1 = sum1 + board[1][8];
    }

    if ((row == 9) and (column == 0)){
      if (board[8][0] == -1)
        sum2+=1;
      if (board[9][1] == -1)
        sum2+=1;
      if (board[8][1] == -1)
        sum2+=1;
      if (board[8][0] > 0)
        sum1 = sum1 + board[8][0];
      if (board[9][1] > 0)
        sum1 = sum1 + board[9][1];
      if (board[8][1] > 0)
        sum1 = sum1 + board[9][1];
    }

    if ((row == 9) and (column == 9)){
      if (board[8][9] == -1)
        sum2+=1;
      if (board[9][8] == -1)
        sum2+=1;
      if (board[8][8] == -1)
        sum2+=1;
      if (board[8][9] > 0)
        sum1 = sum1 + board[8][9];
      if (board[9][8] > 0)
        sum1 = sum1 + board[9][8];
      if (board[8][8] > 0)
        sum1 = sum1 + board[8][8];
    }
    //deal with the situations in four corners
    if ((row==0) and (column>0) and (column<9)){
      if(board[row][column-1] == -1)
        sum2+=1;
      if(board[row][column+1] == -1)
        sum2+=1;
      if(board[row+1][column-1] == -1)
        sum2+=1;
      if(board[row+1][column] == -1)
        sum2+=1;
      if(board[row+1][column+1] == -1)
        sum2+=1;
      if(board[row][column-1] > 0)
        sum1 = sum1 + board[row][column-1];
      if(board[row][column+1] > 0)
        sum1 = sum1 + board[row][column+1];
      if(board[row+1][column-1] > 0)
        sum1 = sum1 + board[row+1][column-1];
      if(board[row+1][column] > 0)
        sum1 = sum1 + board[row+1][column];
      if(board[row+1][column+1] > 0)
        sum1 = sum1 + board[row+1][column+1];
    }

    if ((row==9) and (column>0) and (column<9)){
      if(board[row][column-1] == -1)
        sum2+=1;
      if(board[row][column+1] == -1)
        sum2+=1;
      if(board[row-1][column-1] == -1)
        sum2+=1;
      if(board[row-1][column] == -1)
        sum2+=1;
      if(board[row-1][column+1] == -1)
        sum2+=1;
      if(board[row][column-1] > 0)
        sum1 = sum1 + board[row][column-1];
      if(board[row][column+1] > 0)
        sum1 = sum1 + board[row][column+1];
      if(board[row-1][column-1] > 0)
        sum1 = sum1 + board[row-1][column-1];
      if(board[row-1][column] > 0)
        sum1 = sum1 + board[row-1][column];
      if(board[row-1][column+1] > 0)
        sum1 = sum1 + board[row-1][column+1];
    }

    if ((row>0) and (row<9) and (column == 0)){
      if(board[row-1][column] == -1)
        sum2+=1;
      if(board[row+1][column] == -1)
        sum2+=1;
      if(board[row-1][column+1] == -1)
        sum2+=1;
      if(board[row][column+1] == -1)
        sum2+=1;
      if(board[row+1][column+1] == -1)
        sum2+=1;
      if(board[row-1][column] > 0)
        sum1 = sum1 + board[row-1][column];
      if(board[row+1][column] > 0)
        sum1 = sum1 + board[row+1][column];
      if(board[row-1][column+1] > 0)
        sum1 = sum1 + board[row-1][column+1];
      if(board[row][column+1] > 0)
        sum1 = sum1 + board[row][column+1];
      if(board[row+1][column+1] > 0)
        sum1 = sum1 + board[row+1][column+1];
    }

    if ((row>0) and (row<9) and (column == 9)){
      if(board[row-1][column] == -1)
        sum2+=1;
      if(board[row+1][column] == -1)
        sum2+=1;
      if(board[row-1][column-1] == -1)
        sum2+=1;
      if(board[row][column-1] == -1)
        sum2+=1;
      if(board[row+1][column-1] == -1)
        sum2+=1;
      if(board[row-1][column] > 0)
        sum1 = sum1 + board[row-1][column];
      if(board[row+1][column] > 0)
        sum1 = sum1 + board[row+1][column];
      if(board[row-1][column-1] > 0)
        sum1 = sum1 + board[row-1][column-1];
      if(board[row][column-1] > 0)
        sum1 = sum1 + board[row][column-1];
      if(board[row+1][column-1] > 0)
        sum1 = sum1 + board[row+1][column-1];
    }
    //deal with the situations when coordinates are located in the side but not the corner
    if ((row>0) and (row<9) and (column > 0) and (column < 9)){
      if(board[row-1][column] == -1)
        sum2+=1;
      if(board[row+1][column] == -1)
        sum2+=1;
      if(board[row-1][column-1] == -1)
        sum2+=1;
      if(board[row][column-1] == -1)
        sum2+=1;
      if(board[row+1][column-1] == -1)
        sum2+=1;
      if(board[row-1][column+1] == -1)
        sum2+=1;
      if(board[row][column+1] == -1)
        sum2+=1;
      if(board[row+1][column+1] == -1)
        sum2+=1;

      if(board[row-1][column] > 0)
        sum1 = sum1 + board[row-1][column];
      if(board[row+1][column] > 0)
        sum1 = sum1 + board[row+1][column];
      if(board[row-1][column-1] > 0)
        sum1 = sum1 + board[row-1][column-1];
      if(board[row][column-1] > 0)
        sum1 = sum1 + board[row][column-1];
      if(board[row+1][column-1] > 0)
        sum1 = sum1 + board[row+1][column-1];
      if(board[row-1][column+1] > 0)
        sum1 = sum1 + board[row-1][column+1];
      if(board[row][column+1] > 0)
        sum1 = sum1 + board[row][column+1];
      if(board[row+1][column+1] > 0)
        sum1 = sum1 + board[row+1][column+1];
    }
    //deal with the ordinary situation when the coordinate is not located in the corner or a side
    ins[chance].point = sum1;
    ins[chance].point = sum2;
    score = score + board[row][column];
  
    cout<<"Here is the instruction for this chance."<<endl;
    cout<<sum1<<" "<<sum2<<endl;

  }
}
