#include <iostream>
#include "Player.h"

Player::Player(string name = "")
              :Person(name)
{
    wins = 0;
    losses = 0;
    chips = 3;
}

// Accessors
int Player::getWins()   { return wins; }
int Player::getLosses() { return losses; }
int Player::getChips()  { return chips; }

void Player::setChips(int val)  { chips += val; }
