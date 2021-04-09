#pragma once
#include "Ship.h"
class Battleship :
    public Ship
{
public:
    int armor;
    Battleship(int start_health, int start_armor);
};

