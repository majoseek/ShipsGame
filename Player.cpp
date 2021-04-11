#include "Player.h"
Player::Player(Board p_board,std::string in_name)
{
	name = in_name;
	ammo = std::make_pair(NORMAL_AMMO_QUANTITY, INCENDIARY_AMMO_QUANTITY);
	player_board = p_board;
}

