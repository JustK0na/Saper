#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <iostream>

#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include <ostream>
#include <stdlib.h>

MSTextController::MSTextController(MinesweeperBoard& m, MSBoardTextView& view)
    : board(m)
    , view(view)
{
}

void MSTextController::play() const
{
  char ruch;
  int row, col;
    while (board.getGameState()==RUNNING) {
      std::cout<<"Ilosc nieoznaczonych bomb: "<<board.getMineCount();
      view.display();
      std::cout<<"\nCo chcesz zrobić?\nf - ustaw/zdejmij flage\no - odkryj pole\n";
      std::cin>>ruch;

      if(ruch=='f')
      {
        std::cout<<"Na jakim polu?\nRzad: ";
        std::cin>>row;
        std::cout<<"\nKolumna: ";
        std::cin>>col;
        board.toggleFlag(row, col);
                
      }
      if(ruch=='o')
      {
        std::cout<<"Ktore pole?\nRzad: ";
        std::cin>>row;
        std::cout<<"\nKolumna: ";
        std::cin>>col;
        board.revealField(row, col);
      }
    }
    if(board.getGameState()==FINISHED_LOSS)
    {
      view.display();
      std::cout<<"\nPrzegrales :C\n";
    }
    if(board.getGameState()==FINISHED_WIN)
    {
      view.display();
      std::cout<<"\nWYGRALES!!\n";
    }
}