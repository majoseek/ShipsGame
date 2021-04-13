#pragma once
#include<string>
#define BATTLESHIP_HEALTH 50
#define NORMALSHIP_HEALTH 25
#define BATTLESHIP_ARMOR 10
class Ship
{
public:
	int health;
	std::string type;
	int hit_incendiary;
	Ship(const int& start_health = 0);
	void take_damage(const int& amount);
	bool is_destroyed() const { return health == 0; }
};

std::ostream& operator<<(std::ostream& os, const Ship& ship);
