#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "MSBoardTextView.h"
#include <stdlib.h>

MSBoardTextView::MSBoardTextView(MinesweeperBoard& m)
    : board(m)
{
}
void MSBoardTextView::display() const
{
    std::cout << "\n";

    for (int row = 0; row < (board.getBoardHeight() + 1); row++) {
        if (row < board.getBoardHeight()) {
            std::cout << row << "";

            for (int col = 0; col < board.getBoardWidth(); col++) {
                std::cout << "[";

                std::cout << board.getFieldInfo(row, col);

                std::cout << "]";
            }
        } else {
            std::cout << " ";
            for (int col = 0; col < board.getBoardWidth(); col++)
                std::cout << col << "  ";
        }

        std::cout << "\n";
    }
}