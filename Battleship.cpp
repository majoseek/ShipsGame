#include "Battleship.h"
#include <algorithm>

Battleship::Battleship(int start_health, int start_armor) :Ship(start_health)
{
	armor = start_armor;
	health = start_health;
	type = "BATTLESHIP";
}

void Battleship::take_damage(int amount)
{
	health = std::max(0, health - (amount - armor));
}
