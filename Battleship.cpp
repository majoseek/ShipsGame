#include "Battleship.h"
#include <algorithm>

Battleship::Battleship(const int& start_health, const int& start_armor) :Ship(start_health)
{
	armor = start_armor;
	health = start_health;
	type = "BATTLESHIP";
}

void Battleship::take_damage(const int& amount)
// Method allowing battleships to take damage
{
	health = std::max(0, health - (amount - armor));
}
