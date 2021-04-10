#pragma once
#include "Player.h"
#include "Ship.h"
#include "Ammunition.h"
#include<vector>
class Board
{
public:
	Player player;	//:param: it keeps which player's board is it
	Ship **ships;	//:**param: it keeps board as a matrix
	int board_size;
	Board(std::vector<std::string>input_board = std::vector<std::string>());	//assuming that board is a square
	void hit_ship(int x, int y, Ammunition ammo);
	void remove_ship(int x, int y);
};

