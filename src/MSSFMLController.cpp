#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>

#include <stdlib.h>
#include "MSSFMLController.h"

#include "MinesweeperBoard.h"


MSSFMLController::MSSFMLController(MinesweeperBoard &m)
  :board(m)
{
}
void MSSFMLController::play(sf::RenderWindow &win) const
{

  sf::Event event;
  while(win.pollEvent(event)){

    if (event.type == sf::Event::Closed)
      win.close();
    else  if(event.type == sf::Event::MouseButtonPressed)
      {
	if(event.mouseButton.button == sf::Mouse::Left)
	  {
	    int x,y;
	    x=((event.mouseButton.x-20)/25);
	    y=((event.mouseButton.y-100)/25);
	    board.revealField(y, x);
	  }
	else if(event.mouseButton.button == sf::Mouse::Right)
	  {
	    int x,y;
	    x=((event.mouseButton.x-20)/25);
	    y=((event.mouseButton.y-100)/25);
	    board.toggleFlag(y, x);
	  }
      } 
    
  }
  

  
  
}

 

