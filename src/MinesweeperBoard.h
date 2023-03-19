#include <cstdio>
#include <cwchar>
#include "Array2D.h"
#include <iostream>

#include <stdlib.h>
#include <time.h>

enum GameMode {DEBUG, EASY, NORMAL, HARD};
struct Field
{
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

class MinesweeperBoard
{
Field Board[100][100];
    int width;
    int height;




  public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
    void clear_board();
    void minowanie(GameMode mode);
    int iloscBomb(GameMode mode);  
};