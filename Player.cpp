#include "Player.h"
#include "Status.h"
#include <ostream>
Player::Player(Board p_board,std::string in_name)
{
	name = in_name;
	ammo = std::make_pair(NORMAL_AMMO_QUANTITY, INCENDIARY_AMMO_QUANTITY);
	player_board = p_board;
}


std::string Player::take_shot(int x, int y, Ammunition shoot_ammo)
{
	Status hit_status = player_board.hit_ship(x, y, shoot_ammo);
	if (hit_status == Status::Destroyed)
	{
		remain_ships -= 1;
		return "You destroyed the ship!";
	}
	if (hit_status == Status::Miss)
	{
		return "You missed!";
	}
	return "You hit the ship!";
}


std::ostream& operator<<(std::ostream& os, Player player)
{
	os << player.name << "'s turn. You have " << player.ammo.first << " normal ammunition left and ";
	os << player.ammo.second << " incendiary ammunition left." << std::endl;
	os << "You still have " << player.remain_ships << " ships left.";
	return os;
}