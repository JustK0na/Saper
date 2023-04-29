#!/bin/bash
g++ -c MSSFMLController.cpp MSTextController.cpp Minesweeper.cpp MSFMLview.cpp MSBoardTextView.cpp main.cpp

g++ main.o MSSFMLController.o MSTextController.o Minesweeper.o MSFMLview.o MSBoardTextView.o -o saper -lsfml-graphics -lsfml-window -lsfml-system
