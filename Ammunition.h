#pragma once
#include<string>
#define NORMAL_AMMO_QUANTITY 90
#define INCENDIARY_AMMO_QUANTITY 10
class Ammunition
{
public:
	int damage;
	std::string type;
	Ammunition(int dmg);
};

