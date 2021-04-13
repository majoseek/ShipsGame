#pragma once
#include<string>
// Damages and quantities of every type of the ammuntion
#define NORMAL_AMMO_QUANTITY 90
#define INCENDIARY_AMMO_QUANTITY 10
#define NORMAL_AMMO_DMG 10
#define INCENDIARY_AMMO_DMG 20
class Ammunition
{
public:
	int damage;
	std::string type;
	Ammunition(int dmg);
};

