#ifndef PLAYER_H
#define PLAYER_H
#include <Person.h>

using namespace std;

class Player : public Person
{
    private:
        int wins;
        int losses;
        int chips;
    public:
        Player(string name);

        int getWins();
        int getLosses();
        int getChips();
        void addWin();
        void addLoss();
        void setChips(int val);
};

#endif
