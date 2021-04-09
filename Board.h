#pragma once
#include "Player.h"
#include "Ship.h"
#include "Ammunition.h"
class Board
{
public:
	Player player;	//:param: it keeps which player's board is it
	Ship **ships;	//:**param: it keeps board as a matrix
	Board(char** input_board, int board_size);	//assuming that board is a square
	void hit_ship(int x, int y, Ammunition ammo);
	void remove_ship(int x, int y);
};

