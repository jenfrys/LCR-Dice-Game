#ifndef DICE_H
#define DICE_H

using namespace std;

class Dice
{
    private:
        int num;
        char sides[6];
    public:
        Dice();
        void roll();
        char getSide();
};

#endif
