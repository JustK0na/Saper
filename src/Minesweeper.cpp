#include "Array2D.h"
#include "MinesweeperBoard.h"
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <iostream>

#include <stdlib.h>
#include <time.h>

/*MinesweeperBoard::MinesweeperBoard()
{
  height = 5;
  width = 7;
  
  
  clear_board();
  
  Board[0][0].hasMine=1;
  Board[1][1].isRevealed=1;
  Board[0][2].hasMine=1;
  Board[0][2].hasFlag=1;
}*/
MinesweeperBoard::MinesweeperBoard(int collumns, int rows, GameMode mode)
{
    width = collumns;
    height = rows;
    clear_board();
    bomb = iloscBomb(mode);
    minowanie(mode);
    state = RUNNING;
    first_move = false;
}
int MinesweeperBoard::getBoardHeight() const
{
    return height;
}
int MinesweeperBoard::getBoardWidth() const
{
    return width;
}
int MinesweeperBoard::getMineCount() const
{
    return bomb;
}
bool MinesweeperBoard::is_NOT_on_board(int row, int col) const
{
    if (row > (height - 1) || row < 0 || col > (width - 1) || col < 0)
        return true;
    return false;
}
void MinesweeperBoard::clear_board()
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            Board[row][col].hasMine = 0;
            Board[row][col].hasFlag = 0;
            Board[row][col].isRevealed = 0;
        }
    }
}
int MinesweeperBoard::countMines(int row, int col) const
{

    if (is_NOT_on_board(row, col))
        return -1;
    int tmpCounter = 0;
    if (Board[row][col].isRevealed)
        return -1;

    for (int i = (row - 1); i <= (row + 1); i++)
        for (int j = (col - 1); j <= (col + 1); j++) {
            if (Board[i][j].hasMine)
                tmpCounter++;
        }
    return tmpCounter;
}
bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (is_NOT_on_board(row, col))
        return false;

    if (Board[row][col].isRevealed)
        return false;

    return Board[row][col].hasFlag;
}

GameState MinesweeperBoard::getGameState() const
{
    return state;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (is_NOT_on_board(row, col))
        return;
    if (Board[row][col].isRevealed)
        return;
    if (getGameState() == FINISHED_LOSS || getGameState() == FINISHED_WIN)
        return;

    if (!(Board[row][col].isRevealed)) //Tego nie potrzeba bo poprzedni if sprawdza
        //odwrotny stan (chyba)
        Board[row][col].hasFlag = 1;
}
void MinesweeperBoard::move_mine(int row, int col)
{
    int tmprow = row;
    int tmpcol = col;

    while (Board[tmprow][tmpcol].hasMine == 1) {
        if (is_NOT_on_board(tmprow + 1, tmpcol + 1)) {
            tmprow = 0;
            tmpcol = 0;
        }
        tmprow++;
        tmpcol++;
    }
    Board[tmprow][tmpcol].hasMine = 1;
}
void MinesweeperBoard::revealField(int row, int col)
{
    if (is_NOT_on_board(row, col))
        return;
    if (Board[row][col].isRevealed)
        return;
    if (getGameState() == FINISHED_LOSS || getGameState() == FINISHED_WIN)
        return;
    if (Board[row][col].hasFlag == 1)
        return;

    if (Board[row][col].hasMine == 0)
        Board[row][col].isRevealed = 1;

    if (first_move == 1) //gracz juz się ruszył
    {
        Board[row][col].isRevealed = 1;
        state = FINISHED_LOSS;
    } else if (first_move == 0 && mode != DEBUG) //to pierwszy ruch gracza
    {
        move_mine(row, col);
        Board[row][col].isRevealed = 1;
    }
}
bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (Board[row][col].isRevealed == 1)
        return true;
    return false;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if (is_NOT_on_board(row, col))
        return '#';

    if (Board[row][col].isRevealed == 0 && Board[row][col].hasFlag == 1)
        return 'F';

    if (Board[row][col].isRevealed == 0 && Board[row][col].hasFlag == 0)
        return '_';

    if (Board[row][col].hasMine == 1 && Board[row][col].isRevealed == 1)
        return 'x';
    if (Board[row][col].isRevealed == 1 && countMines(row, col) == 0)
        return ' ';
    if (Board[row][col].isRevealed == 1 && countMines(row, col) != 0) {
        char number;
        number = (countMines(row, col) + 30);
        return number;
    }

    return '!';
}

int MinesweeperBoard::iloscBomb(GameMode mode) const
{
    if ((height * width) % 10 == 0) {
        if (mode == EASY)
            return (width * height) / 10;
        else if (mode == NORMAL)
            return (width * height) / 5;
        else if (mode == HARD)
            return ((width * height) / 10) * 3;
    } else {
        if (mode == EASY)
            return ((width * height) / 10) + 1;
        else if (mode == NORMAL)
            return ((width * height) / 5) + 1;
        else if (mode == HARD)
            return (((width * height) * 3) / 10) + 1;
    }
    return 1;
}
void MinesweeperBoard::minowanie(GameMode mode)
{
    std::srand(time(NULL));
    int bomby = bomb;
    while (bomby > 0) {
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                if (mode == EASY) {
                    if (bomby > 0 && Board[row][col].hasMine == 0)
                        if (std::rand() % 10 == 1) {
                            Board[row][col].hasMine = 1;
                            bomby--;
                        }
                }
                if (mode == NORMAL) {
                    if (bomby > 0 && Board[row][col].hasMine == 0)
                        if (std::rand() % 5 == 1) {
                            Board[row][col].hasMine = 1;
                            bomby--;
                        }
                }
                if (mode == HARD) {
                    if (bomby > 0 && Board[row][col].hasMine == 0) {
                        int random = std::rand() % 10;
                        if (random == 1 || random == 2 || random == 3) {
                            Board[row][col].hasMine = 1;
                            bomby--;
                        }
                    }
                }
                if (mode == DEBUG) {
                    if (row == 0 || row == col || ((row % 2) == 0 && col == 0))
                        Board[row][col].hasMine = 1;
                    bomby--;
                }
            }
        }
    }
}

void MinesweeperBoard::debug_display() const
{

    for (int row = 0; row < (height + 1); row++) {
        //+1 przy height żeby zmieściły się indeksy
        if (row < height)
            std::cout << row << "  ";
        for (int col = 0; col < width; col++) {
            if (row == height) {
                std::cout << "   " << col << " ";
            } else {
                std::cout << "[";

                if (Board[row][col].hasMine)
                    std::cout << "M";
                else
                    std::cout << ".";

                if (Board[row][col].hasFlag)
                    std::cout << "f";
                else
                    std::cout << ".";

                if (Board[row][col].isRevealed)
                    std::cout << "o";
                else
                    std::cout << ".";

                std::cout << "]";
            }
        }
        std::cout << std::endl;
    }
}