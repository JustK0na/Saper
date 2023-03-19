#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include "Array2D.h"
#include <iostream>
#include "MinesweeperBoard.h"

#include <stdlib.h>
#include <time.h>


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
MinesweeperBoard::MinesweeperBoard(int collumns, int rows, GameMode mode)
{
  width = collumns;
  height = rows;
  clear_board();
  minowanie(mode);
  
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
int MinesweeperBoard::iloscBomb(GameMode mode)
{
  if((height*width)%10 == 0)
  {
    if(mode == EASY)
      return (width*height)/10;
    else if (mode == NORMAL)
      return (width*height)/5;
    else if (mode==HARD)
      return ((width*height)/10)*3;
  }
  else 
  {
     if(mode == EASY)
      return ((width*height)/10)+1;
    else if (mode == NORMAL)
      return ((width*height)/5)+1;
    else if (mode==HARD)
      return (((width*height)*3)/10)+1;
  }
  return 1;
}
void MinesweeperBoard::minowanie(GameMode mode)
{
  std::srand(time(NULL));
  int bomby=iloscBomb(mode);
  while(bomby>0)
  {
    for(int row=0; row<height; row++)
    {
      for(int col=0; col<width; col++)
        {
          if(mode==EASY)
          {
            if(bomby>0&&Board[row][col].hasMine==0)
             if(std::rand() % 10 == 1)
             {
               Board[row][col].hasMine=1;
               bomby--;
             }
              
          }
          if(mode==NORMAL)
          {
            if(bomby>0&&Board[row][col].hasMine==0)
             if(std::rand() % 5 == 1)
             {
               Board[row][col].hasMine=1; 
               bomby--;
             }
                           
          }
          if(mode==HARD)
          {
            if(bomby>0&&Board[row][col].hasMine==0)
            {
              int random = std::rand() % 10;
              if(random==1||random==2||random==3)
              {
                Board[row][col].hasMine=1; 
                bomby--;
              }
               
              
            }
              
             
          }
          if(mode==DEBUG)
          {
            if(row==0||row==col||((row%2)==0&&col==0))
              Board[row][col].hasMine=1; 
            bomby--;
          }
        }
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