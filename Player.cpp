#include "Player.h"
Player::Player(std::string in_name, int starting_ships, Ammunition* starting_ammo, Board start_board)
{
	name = in_name;
	remain_ships = starting_ships;
	ammo = starting_ammo;
	player_board = start_board;
}

