/* .
    Mikołaj Strużykowksi 276141
    poniedziałek 9.15
*/
#include "Array2D.h"
#include "MSBoardTextView.h"
#include "MSFMLview.h"
#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdio>
#include <cwchar>
#include <iostream>

#include <stdlib.h>
#include <time.h>


#define WIELNAPOLE 25
#define MARGINES 20
#define WIELGUI 100


int main()
{



    MinesweeperBoard m { 20, 20, DEBUG };
    m.debug_display();
    MSBoardTextView view(m);
    MSTextController ctrl(m, view);
    MSBoardSFMLView window(m);

    sf::RenderWindow win(sf::VideoMode(m.getBoardWidth()*WIELNAPOLE+MARGINES*2, m.getBoardHeight()*WIELNAPOLE+MARGINES*2+WIELGUI), "Saper");
    win.setVerticalSyncEnabled(false);
    win.setFramerateLimit(12);

    m.revealField(12,2);
    m.revealField(13,2);
    m.revealField(14,2);
    m.revealField(15,2);

    std::cout<<"|:"<<m.getFieldInfo(12,2)<<"\t"<<m.getFieldInfo(13,2)<<"\t"<<m.getFieldInfo(14,2)<<"\t"<<m.getFieldInfo(15,2)<<"\t:|";

    m.toggleFlag(10, 5);
    m.toggleFlag(7, 12);
    m.toggleFlag(5, 9);

    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(sf::Color(188,175,189));
        window.present(win);
        win.display();
    }

   // ctrl.play();
}
