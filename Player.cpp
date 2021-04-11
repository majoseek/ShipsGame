#include "Player.h"
Player::Player(Board p_board,std::string in_name, int starting_ships,int normal_ammo_amount,int incendiary_ammo_amout)
{
	name = in_name;
	remain_ships = starting_ships;
	ammo = std::make_pair(normal_ammo_amount, incendiary_ammo_amout);
	player_board = p_board;
}

