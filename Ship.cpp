#include "Ship.h"
#include <algorithm>
#include <ostream>

Ship::Ship(const int& start_health)
{
	health = start_health;
	type = "NORMAL";
	hit_incendiary = 0;
}

void Ship::take_damage(const int& amount)
// Method allowing ships to take damage
{
	health = std::max(0, health - amount);
}

std::ostream& operator<<(std::ostream& os, const Ship& ship)
{
	os << ship.type << " (" << ship.health << "HP left)";
	return os;
}