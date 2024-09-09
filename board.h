#ifndef BOARD_H
#define BOARD_H
#include<string>
#include <iostream>
using namespace std;

extern bool life;
extern string show_board[9][9];
extern int mine;
extern int *xpos;
extern int *ypos;
const int length = 9;

class Board{
private:
  //if is mine or not
  bool is_mine;
  //around mine number in 3X3
  int mine_number;
public:
  //initialize the board
  void init(){
    is_mine = false;
    mine_number = 0;
  }
  //burry mine
  void isMine(){
    is_mine = true;
  }
  //check if is mine
  bool ifMine(){
    return is_mine;
  }
  //around mine number
  int aroundMine(){
    return mine_number;
  }
};

void random_mine(); //random generate a mine map with 10 mines

int mineNumber(int x, int y); //check mine number in 3*3 around

void createGame(); //initialize the game and create a board

void Show_bomb_board(Board b[][9]); //print the bomb board when the player steps on a mine

void Show_show_board(string b[][9]); //print the show board when the player finishes one round

void Auto_Open(int x, int y); //when the player opens a box (row x and column y) that does not contain mine, check the surrounding 3*3 boxs. The box that does not contain mine will be automatically opened

void Mark(int x, int y); //mark a box with "*" (row x and column y)

void Open(int x, int y); //open a box (row x and column y)

bool Win(); //determine whether the player has met the conditions for victory in the game, opening all boxes that do not contain mine

extern Board board[9][9];
#endif
