#pragma once
#include "Ship.h"
class Battleship :
    public Ship
{
public:
    int armor; // reduces incoming damage
    Battleship(const int& start_health, const int& start_armor);
    void take_damage(const int& amount);
};

