#pragma once
#include "Ammunition.h"
#include "Board.h"
class Player
{
public:
	std::string name;
	Board player_board;	//keeps board for each player
	int remain_ships;
	Ammunition* ammo;
	Player(Board p_board,std::string in_name = "", int starting_ships = 0, Ammunition* starting_ammo = NULL);
	void shoot_ship(int x,int y,Ammunition shoot_ammo);
	void take_shot(int x, int y, Ammunition shoot_ammo);
};

