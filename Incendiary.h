#pragma once
#include "Ammunition.h"

#define INCENDIARYDMG 5

class Incendiary :
    public Ammunition
{
public:
    int armor;
    Incendiary(int dmg);
};

