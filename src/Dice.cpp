#include <cstdlib>
#include <ctime>
#include "Dice.h"

Dice::Dice()
{
    srand(time(0));
    num = (rand() % 5) + 0;
    sides[0] = 'X';
    sides[1] = 'L';
    sides[2] = 'X';
    sides[3] = 'C';
    sides[4] = 'X';
    sides[5] = 'R';
}

void Dice::roll()
{
    num = (rand() % 5) + 0;
}

// Accessors
char Dice::getSide()    { return sides[num]; }
