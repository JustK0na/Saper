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
sf::Sprite MSBoardSFMLView::createPole1(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura1.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPole2(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura2.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPole3(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura3.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPole4(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura4.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPole5(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura5.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPole6(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura6.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPole7(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura7.png"))
    {
        std::cout<<"Failed to load a texture \n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(MARGINES+x, WIELGUI+y);
    return sprite;
}
sf::Sprite MSBoardSFMLView::createPole8(float x, float y) const
{
    static sf::Texture texture;
    static sf::Sprite sprite;
    if(!texture.loadFromFile("../src/Graphics/Texture/Textura8.png"))
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
        std::cout<<"\n";
        for (int j = 0; j < board.getBoardHeight(); j++) {
            std::cout<<i<<" "<<j<<"\t";
            if(board.getFieldInfo(i, j) == ' ')
            {
                win.draw(createPolePuste(i*WIELNAPOLE, j*WIELNAPOLE));
            }
            if (board.getFieldInfo(j, i) == '_')
            {
                win.draw(createPole(i*WIELNAPOLE,j*WIELNAPOLE));
            }
            if(board.getFieldInfo(i, j) == 'F')
            {
                win.draw(createPoleFlaga(i*WIELNAPOLE,j*WIELNAPOLE));
            }
            if(board.getFieldInfo(i,j) == 'x')
            {
                win.draw(createPoleBomba(i*WIELNAPOLE,j*WIELNAPOLE));
            }
            else 
            {
                switch (board.getFieldInfo(i,j)) {
                case '1':
                    win.draw(createPole1(i*WIELNAPOLE,j*WIELNAPOLE));
                    break;
                case '2':
                    win.draw(createPole2(i*WIELNAPOLE,j*WIELNAPOLE));
                    break;
                case '3':
                    win.draw(createPole3(i*WIELNAPOLE,j*WIELNAPOLE));
                    break;
                case '4':
                    win.draw(createPole4(i*WIELNAPOLE,j*WIELNAPOLE));
                    break ;
                case '5':
                    win.draw(createPole5(i*WIELNAPOLE,j*WIELNAPOLE));
                    break ;
                case '6':
                    win.draw(createPole6(i*WIELNAPOLE,j*WIELNAPOLE));
                    break ;
                case '7':
                    win.draw(createPole7(i*WIELNAPOLE,j*WIELNAPOLE));
                    break ;
                case '8':
                    win.draw(createPole8(i*WIELNAPOLE,j*WIELNAPOLE));
                    break ;

                }
            }

        }
    }



  
}