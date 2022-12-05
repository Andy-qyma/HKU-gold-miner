//
//  main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>

#include "instruction.h"
#include "initialization.h"
#include "routine.h"

using namespace std;

bool cmp(int x,int y){
    return x>y;
}

class N_S{
  public:
  string N;
  int S;
};

bool operator <(const N_S& a, const N_S& b) {
  if (a.S < b.S) return true;
  if (a.S > b.S) return false;
  return a.N > b.N;
}

int main(){
    //Player is asked to input their name
    string name, line;
    cout<<"Please input your name:"<<endl;
    cin>>name;
    int record_time=0;
    int update_row, update_column;
    int board[ROWS][COLUMNS];
    int map[ROWS][COLUMNS];
    int mode=0;
    string loading_choice;
    ifstream fin;
    ofstream fout;
    fin.open("coordinate.txt");
    char c;
    fin >> c;
    
    if( fin.fail() == false && fin.eof() == false ){
        cout<<"Please input if you want to start from the loading game."<<endl;
        cout<<"Please input Yes / No as your choice."<<endl;
        cin>>loading_choice;
        while ((loading_choice != "No") && (loading_choice != "Yes")){
            cin>>loading_choice;
            cout<<"You entered a wrong word."<<endl;
            cout<<"Please input it again."<<endl;
        }
        if (loading_choice=="No"){
            fstream file1("MAP.txt", ios::out);
            fstream file2("BOARD.txt", ios::out);
            fstream file3("MODE.txt", ios::out);
            fstream f("coordinate.txt", ios::out);
        }
    }
    else{
        loading_choice = "No";
        
    }
    
    string gameEnded = "False";
    while (gameEnded != "True"){
        //function of initial board
        //dynamic array
        Instruction *ins;
        ins = new  Instruction[100];
        
        cout<<endl;
        
        if (loading_choice != "No"){
            int x;
            // Update the mode
            fin.open("MODE.txt");
            fin >> mode;
            fin.close();
            
            // update the map
            fin.open("MAP.txt");
            int i = 0;
            int j = 0;
            while (getline(fin, line)){
                istringstream iss(line);
                while (iss >> x){
                    map[i][j]=x;
                    j++;
                }
                i++;
                j=0;
            }
            fin.close();
            
            // update the board
            fin.open("BOARD.txt");
            i = 0;
            j = 0;
            while (getline(fin, line)){
                istringstream iss(line);
                while (iss >> x){
                    board[i][j]=x;
                    j++;
                }
                i++;
                j=0;
            }
            fin.close();
            
        }
        
        else{
            
            for (int i =0; i < ROWS; i++){
                for (int j =0; j < COLUMNS; j++){
                    board[i][j] = 0;
                }
            }
            //function of the map shown to the player
            
            for (int i =0; i < ROWS; i++){
                for (int j =0; j < COLUMNS; j++){
                    map[i][j] = 0;
                }
            }
            
            instructions(ROWS);
            
            srand((unsigned)time(NULL));
            // int gold is the score of the gold
            // int row column is the position to get the gold
            // using row1 column1 as the index
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
            
            
            //variable mode is to let the player select the mode.
            cout<<"First, please enter the mode you want to play."<<endl;
            cout<<"1-Normal, 2-Adventure"<<endl;
            //change the value of mode to be 0
            int va=0;
            mode=va;
            
            while ((mode<1) || (mode>2)){
                cout<<"Please input a number 1 or 2."<<endl;
                cout<<"The number you input is: ";
                cin>>mode;
            }
            
            // store the mode into a doc of "MODE"
            ofstream fout1;
            fout1.open("MODE.txt",ios::app);
            fout1<< mode << endl;
            
            //the function of setting the mine, using row2 column 2 as the index
            int number;
            int code=0;
            cout<<"Second, please select the difficulty of the game by entering a number from 1,2,3."<<endl;
            //code is the difficulty of the game
            cin>>code;
            while (code<1 or code>3){
                cout<<"Please enter 1, 2, or 3 only: "<<endl;
                cin>>code;
            }
            
            if (code==1)
                number=5;
            if (code==2)
                number=10;
            if (code==3)
                number=15;
            
            srand((unsigned)time(NULL));
            int row2, column2;
            
            while (number > 0){
                row2 = rand()%10;
                column2 = rand()%10;
                if (board[row2][column2] == 0){
                    board[row2][column2] = MINE;
                    number--;
                }
            }
            // store the broad
            ofstream fout;
            fout.open("BOARD.txt",ios::app);
            for (int i =0; i < ROWS; i++){
                for (int j =0; j < COLUMNS; j++){
                    fout<< board[i][j]<<" ";
                }
                fout << endl;
            }
            fout.close();
        }
        
        
        int score=0;
        //variable score is the result of the game
        int row3=0, column3=0;
        int check[5][2];
        int check_adventure[100][2];
        if (mode ==1){
            // update the information regarding board of mode 1
            int record=0;
            if (loading_choice != "No"){
                fin.open("coordinate.txt");
                
                while (getline(fin, line)){
                    istringstream sss(line);
                    sss>>check[record][0]>>check[record][1];
                    score = score + board[check[record][0]-1][check[record][1]-1];
                    record++;
                }
                fin.close();
            }
            
            for (int i=record; i < 5; i++){
                cout<<"Please enter the coordinates you want to mine"<<endl;
                cout<<"The first number you input is the row, the second number you input is the column."<<endl;
                cout<<"Please type them in the same line, and separate them with a space."<<endl;
                cout<<"Eg: if you want to select the point in the 2nd row and the 1st column, please input 2 1"<<endl;
                cout<<"The number you input should be between 1 and 10"<<endl;
                
                cin >> row3 >> column3;
                while ((row3<1) || (row3>10) || (column3<1) || (column3>10)){
                    cout << "Please input number between 1 and 10" << endl;
                    cin >> row3 >> column3;
                }
                //variable row3 and column3 are user inputs of the chosen coordinates
                int k=0;
                while (k==0){
                    int s=0;
                    for (int j=0;j<i;j++){
                        if (check[j][0]==row3 && check[j][1]==column3){
                            s=1;
                            cout<<"You've already selected this coordinates. Please input another coordinates:"<<endl;
                            cin>>row3>>column3;
                            while ((row3<1) || (row3>10) || (column3<1) || (column3>10)){
                                cout << "Please input number between 1 and 10" << endl;
                                cin >> row3 >> column3;
                            }
                        }
                    }
                    if (s==0) break;
                }
                check[i][0]=row3;
                check[i][1]=column3;
                
                //record the coordinator input of mode 1
                fout.open("coordinate.txt",ios::app);
                for (int j =0; j < 2; j++){
                    fout<< check[i][j]<<" ";
                }
                fout << endl;
                fout.close();
                
                routine(ins, board, map, (row3-1), (column3-1), i, score);
                cout<<"Current score: "<<score<<endl<<endl;
                if (board[row3-1][column3-1] == -1)
                    break;
            }
            record_time=0;
            cout<<"Your final score for the game is: "<<score<<endl;
            fstream file1("MAP.txt", ios::out);
            fstream file2("BOARD.txt", ios::out);
            fstream file3("MODE.txt", ios::out);
            fstream f("coordinate.txt", ios::out);
            
            //Below, streams is used to store the historical highest score.
            ofstream fout;
            fout.open("SCORE.txt",ios::app);
            fout<<name<<" "<<score<<endl;
            fout.close();
            ifstream fin;
            fin.open("SCORE.txt");
            int *s_record=new (nothrow) int[10000];
            int i=0;int j=0;
            while (!fin.eof()){
                string name0;
                int score0;
                fin>>name0>>score0;
                if (name0==name){
                    j++;
                    s_record[i]=score0;
                    i++;
                }
            }
            fin.close();
            sort(s_record,s_record+j,cmp);
            cout<<"Your best score ever: "<<s_record[0]<<endl;
            delete [] s_record;
            
            //Below, the ranking (the 1st, 2nd, and 3rd place) of the historical players are printed.
            N_S *n_s=new (nothrow) N_S[10000];
            j=0;
            fin.open("SCORE.txt");
            string str;
            while (getline(fin,str)){
                istringstream iss(str);
                iss>>(n_s+j)->N>>(n_s+j)->S;
                j++;
            }
            fin.close();
            sort(n_s,n_s+j);
            
            cout<<"The 1st, 2nd, 3rd ranking of all historial players is:\n"<<n_s[j-1].N<<endl;
            int k4=0;
            for (int k1=j-2;k1>=0;k1--) {
                int k3=0;
                for (int k2=j-1;k2>k1;k2--){
                    if (n_s[k1].N==n_s[k2].N){
                        k3=1;
                        break;
                    }
                }
                if (k3==0){
                    cout<<n_s[k1].N<<endl;
                    k4++;
                }
                if (k4==2)
                    break;
            }
            cout<<"Note: for players having same historically highest scores, they are ranked alphabetically by their names."<<endl;
            cout<<"If they are two 3rd place players, only one is shown according to their names' alphpabetical orders."<<endl;
            
            //free the memory
            delete []n_s;
            
            
            //ask player whether to play again
            gameEnded = "True";
            string restart;
            if (gameEnded == "True"){
                cout << "Do you wanna play again? (Type \"Yes\" or \"No\")" << endl;
                cin >> restart;
                while ((restart != "Yes") && (restart != "No"))
                {
                    cout << "Do you wanna play again? (Type \"Yes\" or \"No\")"<<endl;
                    cin >> restart;
                }
                if (restart == "Yes"){
                    gameEnded = "False";
                    loading_choice="No";
                    }
                else if (restart == "No")
                    cout << "Bye bye ~";
            }
        }
        
        if (mode == 2){
            // update the information regarding board of mode 2
            int record1=0;
            if (loading_choice != "No"){
                
                fin.open("coordinate.txt");
                
                while (getline(fin, line)){
                    istringstream sss(line);
                    sss>>check_adventure[record1][0]>>check_adventure[record1][1];
                    score = score + board[check_adventure[record1][0]-1][check_adventure[record1][1]-1];
                    record1++;
                }
                fin.close();
            }
            else
              loading_choice = "No";
            for (int i = record1; i<100; i++){
                cout<<"Please enter the coordinates you want to mine"<<endl;
                cout<<"The first number you input is the row, the second number you input is the column."<<endl;
                cout<<"Please type them in the same line, and separate them with a space."<<endl;
                cout<<"Eg: if you want to select the point in the 2nd row and the 1st column, please input 2 1"<<endl;
                cout<<"The number you input should be between 1 and 10"<<endl;
                
                cin >> row3 >> column3;
                while ((row3<1) || (row3>10) || (column3<1) || (column3>10)){
                    cout << "Please input number between 1 and 10" << endl;
                    cin >> row3 >> column3;
                }
                //variable row3 and column3 are user inputs of the chosen coordinates
                int k=0;
                while (k==0){
                    int s=0;
                    for (int j=0;j<i;j++){
                        if (check_adventure[j][0]==row3 && check_adventure[j][1]==column3){
                            s=1;
                            cout<<"You've already selected this coordinates. Please input another coordinates:"<<endl;
                            cin>>row3>>column3;
                            while ((row3<1) || (row3>10) || (column3<1) || (column3>10)){
                                cout << "Please input number between 1 and 10" << endl;
                                cin >> row3 >> column3;
                            }
                        }
                    }
                    if (s==0) break;
                }
                check_adventure[i][0]=row3;
                check_adventure[i][1]=column3;
                //record the coordinator input of mode 2
                fout.open("coordinate.txt",ios::app);
                for (int j =0; j < 2; j++){
                    fout<< check_adventure[i][j]<<" ";
                }
                fout << endl;
                fout.close();
                
                routine(ins, board, map, (row3-1), (column3-1), i, score);
                cout<<"Current score: "<<score<<endl<<endl;
                if (board[row3-1][column3-1] == -1)
                    break;
            }
            record_time=0;
            cout<<"Your final score for the game is: "<<score<<endl;
            fstream file1("MAP.txt", ios::out);
            fstream file2("BOARD.txt", ios::out);
            fstream file3("MODE.txt", ios::out);
            fstream f("coordinate.txt", ios::out);
            
            //ask player whether to play again
            gameEnded = "True";
            string restart;
            if (gameEnded == "True"){
                cout << "Do you wanna play again? (Type \"Yes\" or \"No\")" << endl;
                cin >> restart;
                while ((restart != "Yes") && (restart != "No")){
                    cout << "Do you wanna play again? (Type \"Yes\" or \"No\")"<<endl;
                    cin >> restart;
                }
                if (restart == "Yes"){
                    gameEnded = "False";
                    loading_choice="No";
                    }
                else if (restart == "No")
	    	cout << "Bye bye ~"<<endl;
            }
        }
        delete []ins;
    }
}

    


