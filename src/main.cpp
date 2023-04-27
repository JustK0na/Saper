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

int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "Saper");
    win.setVerticalSyncEnabled(false);
    win.setFramerateLimit(2);

    MinesweeperBoard m { 2, 2, EASY };
    m.debug_display();
    MSBoardTextView view(m);
    MSTextController ctrl(m, view);
    MSBoardSFMLView window(m);

    while (win.isOpen()) {
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        win.clear(sf::Color(0, 0, 0, 255));
        window.draw();
        win.display();
    }

   // ctrl.play();
}
