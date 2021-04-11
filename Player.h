#pragma once
#include "Ammunition.h"
#include "Board.h"
#include<utility>
class Player
{
public:
	std::string name;
	Board player_board;	//keeps board for each player
	std::pair<int,int>ammo;	//<normal_ammunition,incendiary_ammunition>
	Player(Board p_board=Board(std::vector<std::string>()),std::string in_name = "");
	std::string take_shot(int x, int y, Ammunition shoot_ammo);
	bool has_ammo() { return (ammo.first > 0 || ammo.second > 0); }
};

std::ostream& operator<<(std::ostream& os, Player player);