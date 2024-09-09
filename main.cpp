#include"board.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

extern Board board[9][9];
extern int mine;
extern int *xpos;
extern int *ypos;

int main(){

  int command;

  cout << "Game Start!" << endl;
  cout << "Game objective: Open all blocks without mines" << endl;
  cout << "Select operation:" << endl;
  cout << "Enter '0' for starting a game" << endl;
  cout << "Wait, Wandering the mine map of last time?" << endl;
  cout << "Enter '1' for printing the coordinates of the mines in the most recent game" << endl;
  cin >> command;
  if (command == 0){
    Board board[9][9];
    createGame();
    ofstream outfile;
    outfile.open("gamedata.txt");

    for (int i = 0; i < 9; i++){
      outfile << xpos[i] << ' ';
    }
    outfile << xpos[9] << endl;

    for (int i = 0; i < 9; i++){
      outfile << ypos[i] << ' ';
    }
    outfile << ypos[9];

    outfile.close();
    Show_show_board(show_board);
  }

  else if (command == 1){
    Board board[9][9];
    int x[10];
    int y[10];
    ifstream infile;
    infile.open("gamedata.txt");
    for (int i = 0; i < 10; i++){
      infile >> x[i];
    }
    for (int i = 0; i < 10; i++){
      infile >> y[i];
    }

    cout << "the coordinates of the mines in the most recent game:" << endl;
    for (int i = 0; i < 10; i++){
      cout << "row: " << x[i] << ' ' << "column: " << y[i] << endl;
    }
    infile.close();
    cout << "Enter '0' for starting a new game" << endl;
    cout << "Enter '1' for quitting" << endl;
    int opt;
    cin >> opt;
    if (opt == 0){
      Board board[9][9];
      createGame();
      ofstream outfile;
      outfile.open("gamedata.txt");

      for (int i = 9; i >= 0; i--){
        outfile << xpos[i] << ' ';
      }
      outfile << endl;
      for (int i = 9; i >= 0; i--){
        outfile << ypos[i] << ' ';
      }

      outfile.close();
      Show_show_board(show_board);
    }
    else if (opt == 1){
      return 0;
    }
  }

  while(1){
    if (life == false){
      Show_bomb_board(board);
      cout << "Sorry you step on a bomb. Game Over!" << endl;
      break;
    }
    else if (Win() == true){
      cout << "Sweep all the bombs! Congratulations!" << endl;
      break;
    }
    else{
      int command;
      int x; int y;
      cout << "Select operation:" << endl;
      cout << "Enter '0' for marking a block" << endl;
      cout << "Enter '1' for opening a block" << endl;
      cout << "Enter '2' for quitting" << endl;
      cin >> command;
      if (command == 0){
        cout << "Please enter coordinate (row, column)" << endl;
        cin >> x >> y;
        Mark(x, y);
        Show_show_board(show_board);
        Win();
      }
      else if (command == 1){
        cout << "Please enter coordinate (row, column)" << endl;
        cin >> x >> y;
        Open(x, y);
        if (life == false){
          continue;
        }
        else{
          Show_show_board(show_board);
          Win();
        }
      }
      else if (command == 2){
        return 0;
      }
    }
  }
}
