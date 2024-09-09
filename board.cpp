#include"board.h"
#include<string>
using namespace std;

string show_board[9][9];
int mine = 10;
bool life = true;
Board board[9][9];
int *xpos = new int[mine];
int *ypos = new int[mine];
