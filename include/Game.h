#ifndef GAME_H
#define GAME_H
#include <string>
#include "Dice.h"
#include "Player.h"

using namespace std;

class Game
{
    private:
        Player player1, player2, player3;
        Dice die;
        int center;
        int turns;
    public:
        Game(string p1, string p2, string p3);
        Player* getPlayer(int x);
        void addTurn();
        void takeTurn();
        void checkDice(char side, Player *active);
        void rollDice(Player *active);
        bool checkWin();
};

#endif
