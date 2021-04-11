#pragma once
#include "Ammunition.h"
#include "Board.h"
class Player
{
	std::string name;
	Board player_board;
	int remain_ships;
	Ammunition* ammo;
	Player(Board start_board,std::string in_name = "", int starting_ships = 0, Ammunition* starting_ammo = NULL);
	void shoot_ship(int x,int y,Ammunition shoot_ammo);
	void take_shot(int x, int y, Ammunition shoot_ammo);
};

