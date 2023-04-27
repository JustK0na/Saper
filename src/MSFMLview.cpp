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
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(100, 250, 50));
    std::cout<<"drawing...\n";
  
}