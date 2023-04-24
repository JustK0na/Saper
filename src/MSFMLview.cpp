#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdio>
#include <cwchar>
#include <iostream>

#include "MinesweeperBoard.h"
#include "MSFMLview.h"
#include <SFML/Window/VideoMode.hpp>
#include <stdlib.h>
#include <time.h>

MSBoardSFMLView::MSBoardSFMLView(MinesweeperBoard& m)
    : board(m)
{
}
void MSBoardSFMLView::draw() const
{
  sf::RectangleShape rect(sf::Vector2f(300,300));
  rect.setFillColor(sf::Color(124,90,0,255));
  rect.setPosition(10.f,50.f);
  std::cout<<"drawing...\n";
  
}