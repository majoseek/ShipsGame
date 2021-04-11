#include "Battleship.h"
Battleship::Battleship(int start_health, int start_armor) :Ship(start_health)
{
armor = start_armor;
health = start_health;
type = "BATTLESHIP";
}