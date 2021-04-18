#pragma once
#include "Ammunition.h"

#define INCENDIARYDMG 5

class Incendiary :
    public Ammunition
{
public:
    Incendiary(const int& dmg);
};

