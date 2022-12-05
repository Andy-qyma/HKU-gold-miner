// instruction.cpp

#include <iostream>
#include "instruction.h"
using namespace std;


void instructions(int n){
  cout<<"Welcome to the HKU-Gold-Mine game!"<<endl;
  cout<<endl;
  cout<<"In this name, your role is a miner."<<endl;
  cout<<"You need to win the most amount of gold you can within 5 chances in the normal mode."<<endl;
  cout<<"In the adventure mode, your goal is to win as much gold as you can until all the gold are mined or you mine the bomb."<<endl;
  cout<<"The map given is a 10*10 table where each unit has gold, bomb, or simply nothing."<<endl;
  cout<<"There are both gold and bombs within the map."<<endl;
  cout<<"If you successfully mine the gold, the amount of gold will be added as scores."<<endl;
  cout<<"Note that the amount of gold in each coordinates ranges from 1 to 30 and not equal to each other."<<endl;
  cout<<"If you mine the bomb, that means the end of the game."<<endl;
  cout<<"Your score for this round will be the sum of the previous gold you mine."<<endl;
  cout<<endl;
  cout<<"Everytime you decide to mine a certain point in the table, you need to input the corresponding coordinates."<<endl;
  cout<<"After the gold is mined, if it is not a bomb, you will get some instructions."<<endl;
  cout<<"In the instruction, there will be two numbers in a row"<<endl;
  cout<<"The first number is the total amount of gold in the 3*3 table around and exclude the selected coordinates."<<endl;
  cout<<"The second number is the number of bombs in the 3*3 table around the selected coordinates."<<endl;
  cout<<"The game has three difficulty, 1-easy, 2-intermediate, 3-hard"<<endl;
  cout<<endl;
  cout<<"Good luck! Hope you can win a lot of gold there!"<<endl;
  cout<<endl;
}
