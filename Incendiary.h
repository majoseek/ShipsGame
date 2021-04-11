#pragma once
#include "Ammunition.h"
class Incendiary :
    public Ammunition
{
public:
    int armor;
    Incendiary(int dmg);
};

