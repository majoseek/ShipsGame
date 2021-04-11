#include "Ship.h"
Ship::Ship(int start_health, std::string in_type)
{
	health = start_health;
	type = in_type;
}

void Ship::take_damage(int amount)
{
	health = max(0, health - amount);
}

std::ostream& operator<<(std::ostream& os, const Ship& ship)
{
	os << ship.type << " (" << ship.health << "HP left)";
	return os;
}