/* .
    Mikołaj Strużykowksi 276141
    poniedziałek 9.15
*/
#include "Array2D.h"
#include "MSBoardTextView.h"
#include "MSFMLview.h"
#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSSFMLController.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdio>
#include <cwchar>
#include <iostream>

#include <stdlib.h>
#include <time.h>


#define WIELNAPOLE 25
#define MARGINES 20
#define WIELGUIHEIGHT 300
#define WIELGUI 100


int main()
{



  MinesweeperBoard m { 12,12, NORMAL};
    m.debug_display();
    MSBoardTextView view(m);
    MSTextController ctrl(m, view);
    MSSFMLController controller(m);
    MSBoardSFMLView window(m);

    sf::RenderWindow win(sf::VideoMode(m.getBoardHeight()*WIELNAPOLE+MARGINES*2, m.getBoardWidth()*WIELNAPOLE+MARGINES*2+WIELGUI), "Saper");
    win.setVerticalSyncEnabled(false);
    win.setFramerateLimit(12);

    /*  m.revealField(1,2);
    m.revealField(4,2);
    m.revealField(2,4);
    m.revealField(10,0);*/

    /*  std::cout<<"|:"<<m.getFieldInfo(1,2)<<"\t"<<m.getFieldInfo(2,10)<<"\t"<<m.getFieldInfo(2,4)<<"\t"<<m.getFieldInfo(1,10)<<":|\n";
    std::cout<<"|:"<<m.getBoardWidth()<<"\t"<<m.getBoardHeight() << ":|";

    m.toggleFlag(10, 5);
    m.toggleFlag(7, 12);
    m.toggleFlag(5, 9);*/

    while (win.isOpen()) {
        sf::Event event;
        
	controller.play(win);
        
        win.clear(sf::Color(188,175,189));
        window.present(win);
        win.display();
    }

}
