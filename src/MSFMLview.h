#ifndef MSBOARDSFMLVIEW_H__
#define MSBOARDSFMLVIEW_H__

#include <cstdio>
#include <cwchar>
#include <iostream>
#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <time.h>
#include "MinesweeperBoard.h"
#include <SFML/Window/VideoMode.hpp>

class MSBoardSFMLView
{
  MinesweeperBoard & board;
  public:
    MSBoardSFMLView(MinesweeperBoard &board);
    void present(sf::RenderWindow &win) const;
    sf::Sprite createPole(float x, float y) const;
    sf::Sprite createPolePuste(float x, float y) const;
    sf::Sprite createPoleFlaga(float x, float y) const;
    sf::Sprite createPoleBomba(float x, float y) const;
};


#endif