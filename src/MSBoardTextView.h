#ifndef MSBOARDTEXTVIEW_H__
#define MSBOARDTEXTVIEW_H__

#include <cstdio>
#include <cwchar>
#include <iostream>
#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"


class MSBoardTextView
{
  MinesweeperBoard & board;
  public:
    MSBoardTextView(MinesweeperBoard &board);
    void display() const;
};

#endif