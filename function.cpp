#include"board.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

extern int mine;
extern int *xpos;
extern int *ypos;

//random generate a mine map with 10 mines
void random_mine(){
  unsigned seed = time(NULL);
  srand(seed);
  while (mine > 0){
    int x = length, y = length;
    while (board[x][y].ifMine() == true || x >= length || y >= length){
      x = rand() % length;
      y = rand() % length;
    }
   board[x][y].isMine();
   xpos[mine - 1] = x;
   ypos[mine - 1] = y;
   mine --;
  }
}

//check mine number in 3*3 around
int mineNumber(int x, int y){
  int num = 0;
  if (board[x][y].ifMine() == true){
    return 0;
  }
  else{
    for (int i = -1; i < 2; i++){
      for (int j = -1; j < 2; j++){
        int nx = x + i;
        int ny = y + j;
        if (!(ny == y && nx == x) && (nx >= 0 && nx <= length - 1) && (ny >= 0 && ny <= length - 1)){
          if (board[nx][ny].ifMine()){
            num = num + 1;
          }
        }
      }
    }
    board[x][y].aroundMine();
    return num;
  }
}

//initialize the game and create a board
void createGame(){
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      board[i][j].init();
      show_board[i][j] = "■";
    }
  }
  random_mine();
}

//print the bomb board
//print when the player steps on a mine
void Show_bomb_board(Board b[][9]){
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (j == 0){
        cout << "|";
      }

      if (b[i][j].ifMine() == false){
        cout << "■|";
      }
      else{
        cout << "X|";
      }

    }
    cout << endl;
  }
}

//print the show board
//print when the player finishes one round
void Show_show_board(string b[][9]){
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (j == 0){
        cout << "|";
      }

      if (b[i][j] == "0"){
        cout << " |";
      }
      else{
        cout << b[i][j] << "|";
      }
    }
    cout << endl;
  }
}

//when the player opens a box (row x and column y) that does not contain mine
//check the surrounding 3*3 boxs
//the box that does not contain mine will be automatically opened
void Auto_Open(int x, int y){
  for (int i = -1; i < 2; i++){
    for (int j = -1; j < 2; j++){
      int nx = x + i;
      int ny = y + j;
      if (!(ny == y && nx == x) && (nx >= 0 && nx <= length - 1) && (ny >= 0 && ny <= length - 1) && show_board[nx][ny] == "■"){
        if (mineNumber(nx,ny) == 0){
          show_board[nx][ny] = to_string(0);
          Auto_Open(nx,ny);
        }
        else{
          show_board[nx][ny] = to_string(mineNumber(nx,ny));
        }
      }
    }
  }
}

//mark a box with "*" (row x and column y)
void Mark(int x, int y){
  show_board[x][y] = "*";
}

//open a box (row x and column y)
void Open(int x, int y){
  if (board[x][y].ifMine() == true){
    life = false;
  }
  else{
    if (mineNumber(x,y) == 0){
      Auto_Open(x,y);
      show_board[x][y] = "0";
    }
    else{
      show_board[x][y] = to_string(mineNumber(x,y));
    }
  }
}

//determine whether the player has met the conditions for victory in the game, opening all boxes that do not contain mine
bool Win(){
  int n = 0;
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (show_board[i][j] == "*"){
        n += 1;
      }
      else if (show_board[i][j] == "■"){
        n += 1;
      }
    }
  }
  if (n == 10){
    return true;
  }
  else{
    return false;
  }
}
