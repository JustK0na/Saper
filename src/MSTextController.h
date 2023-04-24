#ifndef MSTEXTCONTROLLER_H__
#define MSTEXTCONTROLLER_H__

#include <cstdio>
#include <cwchar>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <stdlib.h>
#include <time.h>

class MSTextController {
    MinesweeperBoard& board;
    MSBoardTextView& view;

public:
    MSTextController(MinesweeperBoard& board, MSBoardTextView& view);
    void play() const;
};
#endif