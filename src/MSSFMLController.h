#ifndef MSSFMLCONTROLLER_H_
#define MSSFMLCONTROLLER_G_


#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>

#include "MinesweeperBoard.h"
#include <SFML/Window/VideoMode.hpp>


class MSSFMLController
{
  MinesweeperBoard & board;
 public:
  MSSFMLController(MinesweeperBoard &board);
  void play(sf::RenderWindow &win) const;
  

  
}
;




#endif
