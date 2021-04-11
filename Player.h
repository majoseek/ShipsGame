#pragma once
#include "Ammunition.h"
#include "Board.h"
#include<utility>
class Player
{
public:
	std::string name;
	Board player_board;	//keeps board for each player
	int remain_ships;
	std::pair<int,int>ammo;	//<normal_ammunition,incendiary_ammunition>
	Player(Board p_board=Board(std::vector<std::string>()),std::string in_name = "", int starting_ships = 0,int normal_ammo_amount=0,int incendiary_ammo_amount=0);
	void shoot_ship(int x,int y,Ammunition shoot_ammo);
	void take_shot(int x, int y, Ammunition shoot_ammo);
};

