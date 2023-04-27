#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <cstdio>
#include <cwchar>
#include <iostream>

#include "MinesweeperBoard.h"
#include "MSFMLview.h"
#include <SFML/Window/VideoMode.hpp>
#include <stdlib.h>
#include <time.h>


#define WIELNAPOLE 25
#define MARGINES 20
#define WIELGUI 100


MSBoardSFMLView::MSBoardSFMLView(MinesweeperBoard& m)
    : board(m)
{
}

sf::RectangleShape MSBoardSFMLView::createPole(float x, float y) const
{
    sf::RectangleShape pole(sf::Vector2f(WIELNAPOLE,WIELNAPOLE));
    pole.setFillColor(sf::Color(133, 123, 132));
    pole.setOutlineThickness(2);
    pole.setOutlineColor(sf::Color(82, 76, 81));
    pole.setPosition(MARGINES+x, WIELGUI+y);
    return pole;
}
void MSBoardSFMLView::present(sf::RenderWindow &win) const
{

    for(int i=0; i<board.getBoardWidth(); i++)
    {
        for (int j = 0; j < board.getBoardHeight(); ++j) {
            if (board.getFieldInfo(i, j) == 'x')
            {
                win.draw(createPole(i*WIELNAPOLE,j*WIELNAPOLE));
            }

        }
    }


    std::cout<<"drawing...\n";
  
}