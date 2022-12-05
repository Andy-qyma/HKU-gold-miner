//
//  routine.h


#ifndef routine_h
#define routine_h

struct Instruction{
  int point;
  int bomb;
  int result;
};
//this struct is used for later instruction output when the user select the position
//point represents the total number(points) of the gold around the selected area
//bomb irepresents the number of bombs around the selected area
//result represents the score the player get in this chance
const int ROWS = 10;
const int COLUMNS = 10;
const int MINE = -1;


void routine(Instruction *ins, int board[ROWS][COLUMNS], int map[ROWS][COLUMNS], int row, int column, int chance, int &score);


#endif /* routine_h */
