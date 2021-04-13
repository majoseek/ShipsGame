#pragma once
#include "Ship.h"
class Battleship :
    public Ship
{
public:
    int armor; // reduces incoming damage
    Battleship(int start_health, int start_armor);
    void take_damage(int amount);
};

