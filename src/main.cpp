/* 
    Imię i nazwisko, nr albumu
    Termin zajęć

    np.
    Jan Kowalski, 123456
    poniedziałek 9.15
.
    Mikołaj Strużykowksi 276141
    poniedziałek 9.15
*/
#include "Array2D.h"
#include "MinesweeperBoard.h"
#include <cstdio>
#include <cwchar>
#include <iostream>

#include <stdlib.h>
#include <time.h>

int main()
{
    MinesweeperBoard m { 10, 10, DEBUG };
    m.debug_display();
}
