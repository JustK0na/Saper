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

sf::Sprite MSBoardSFMLView::createPole(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/TexturaPelne.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPolePuste(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/TexturaPuste.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPoleFlaga(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/TexturaFlaga.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPoleBomba(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/TexturaBomba.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
void MSBoardSFMLView::present(sf::RenderWindow &win) const
{

    for(int i=0; i<board.getBoardWidth(); i++)
    {
        for (int j = 0; j < board.getBoardHeight(); j++) {
            if(board.getFieldInfo(i, j) == ' ')
            {
                win.draw(createPolePuste(i*WIELNAPOLE, j*WIELNAPOLE));
            }
            if (board.getFieldInfo(i, j) == '_')
            {
                win.draw(createPole(i*WIELNAPOLE,j*WIELNAPOLE));
            }
            if(board.getFieldInfo(i, j) == 'F')
            {
                win.draw(createPoleFlaga(i*WIELNAPOLE,j*WIELNAPOLE));
            }


        }
    }



  
}