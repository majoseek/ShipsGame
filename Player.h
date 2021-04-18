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
	std::vector<std::string> logs;	//:param[]: keeps history of made moves
	int remain_ships;
	Player(const int& starting_ships=0, const Board& p_board=Board(std::vector<std::string>()), const std::string& in_name = "");
	std::string take_shot(const int& x,const int& y,const Ammunition& shoot_ammo, const std::string& shooter_name);
	bool has_ammo() const { return (ammo.first > 0 || ammo.second > 0); }
};

std::ostream& operator<<(std::ostream& os, const Player& player);