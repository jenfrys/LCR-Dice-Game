#include <iostream>
#include <cstdlib>
#include "Game.h"

using namespace std;

Game::Game(string p1, string p2, string p3)
          :player1(p1), player2(p2), player3(p3)
{
    center = 0;
    turns = 0;
}

void Game::addTurn() { turns++; }

Player* Game::getPlayer(int x)
{
    switch(x % 3)
    {
    case 1:
        return &player2;
    case 2:
        return &player3;
    default:
        return &player1;
    }
}

void Game::takeTurn()
{
    Player *active = getPlayer(turns);
    cout<<active->getName()<<", it's your turn";
    if(active->getChips() > 0)
    {
        cout<<". You have "<<active->getChips()<<" chip(s).\n"<<endl;
        cout<<"Press Enter to roll the dice."<<endl;
        cin.ignore(100, '\n');
        rollDice(active);
        cout<<"\nYou have "<<active->getChips()<<" chip(s) left.\n"<<endl;
    }
    else
    {
        cout<<" but you do not have any chips left.\n"<<endl;
    }
    cout<<"------------------------------\n\n\n";
}

void Game::rollDice(Player *active)
{
    int chips = active->getChips();

    if(chips >= 3)
    {
        for(int x = 0; x < 3; ++x)
        {
            cout<<"Die "<<x+1<<": ";
            die.roll();
            checkDice(die.getSide(), active);
        }
    }
    else if(chips > 0 && chips < 3)
    {
        for(int x = 0; x < chips; ++x)
        {
            cout<<"Die "<<x+1<<": ";
            die.roll();
            checkDice(die.getSide(), active);
        }
    }
}

void Game::checkDice(char side, Player *active)
{
    Player *playerL = getPlayer(turns+1);
    Player *playerR = getPlayer(turns+2);

    switch(side)
    {
    case 'L':
        cout<<"You rolled an L. Pass a chip to "<<playerL->getName()<<"."<<endl;
        playerL->setChips(1);
        active->setChips(-1);
        break;
    case 'C':
        cout<<"You rolled a C. Add a chip to the center pot."<<endl;
        active->setChips(-1);
        center++;
        break;
    case 'R':
        cout<<"You rolled an R. Pass a chip to "<<playerR->getName()<<"."<<endl;
        playerR->setChips(1);
        active->setChips(-1);
        break;
    default:
        cout<<"You rolled a dot. Keep a chip."<<endl;
        break;
    }
}

bool Game::checkWin()
{
    if(player2.getChips() == 0 && player3.getChips() == 0)
    {
        cout<<player1.getName()<<" is the winner!"<<endl;
        return true;
    }
    if(player1.getChips() == 0 && player3.getChips() == 0)
    {
        cout<<player2.getName()<<" is the winner!"<<endl;
        return true;
    }
    if(player1.getChips() == 0 && player2.getChips() == 0)
    {
        cout<<player3.getName()<<" is the winner!"<<endl;
        return true;
    }
    return false;
}
