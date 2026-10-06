#pragma once
#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster : public GameCharacter
{
private:
    string type;
public:
    Monster();
    Monster(string, int, int, int,string);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
    void printinfo();
    bool isdead();
    string gettype();
};

#endif // ENEMY_H_INCLUDED
