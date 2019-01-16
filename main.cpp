#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game lcr("Jackie", "Eleanor", "Martha");

    do
    {
        lcr.takeTurn();
        lcr.addTurn();
    } while(!lcr.checkWin());

    return 0;
}
