/* 
    Imię i nazwisko, nr albumu
    Termin zajęć

    np.
    Jan Kowalski, 123456
    poniedziałek 9.15
*/
#include <cstdio>
#include <cwchar>
#include "Array2D.h"
#include <iostream>

struct Field
{
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

class MinesweeperBoard
{
    Field Board[100][100];
    int width;
    int height;




  public:
    MinesweeperBoard();
    void debug_display() const;
    void clear_board();
};

MinesweeperBoard::MinesweeperBoard()
{
  height = 5;
  width = 7;
  
  
  clear_board();
  
  Board[0][0].hasMine=1;

  
  Board[1][1].isRevealed=1;

  Board[0][2].hasMine=1;
  Board[0][2].hasFlag=1;
}

void MinesweeperBoard::clear_board()
{
  for(int row=0; row<height; row++)
    {
      for(int col=0; col<width; col++)
        {
          Board[row][col].hasMine=0;
          Board[row][col].hasFlag=0;
          Board[row][col].isRevealed=0;
          
        }
    }
}
void MinesweeperBoard::debug_display() const
{
  
  for(int row=0; row<(height+1); row++)
    {
      //+1 przy height żeby zmieściły się indeksy
      if(row<height)
      std::cout<<row<<"  ";
      for(int col=0; col<width; col++)
        {
          if(row==height)
            {
              std::cout<<"   "<<col<<" ";
            }
          else 
          {
            std::cout<<"[";

          
          if(Board[row][col].hasMine)
            std::cout<<"M";
          else
            std::cout<<".";

          if(Board[row][col].hasFlag)
            std::cout<<"f";
          else
            std::cout<<".";

          if(Board[row][col].isRevealed)
            std::cout<<"o";
          else
            std::cout<<".";

          std::cout<<"]";
          }
        }
      std::cout<<std::endl;
    }
  
}


int main()
{
  /*
    Array2D<int> foo;
    foo.resize(1, 1);
  */
  MinesweeperBoard m;
  m.debug_display();

}
