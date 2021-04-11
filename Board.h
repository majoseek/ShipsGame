#pragma once
#include "Ship.h"
#include "Ammunition.h"
#include "Incendiary.h"
#include<vector>
#include "Status.h"
#define MAX_BATTLESHIPS 2
#define MAX_NORMAL_SHIPS 6
#define BATTLESHIP_SIGN '#'
#define NORMAL_SHIP_SIGN '@'
#define BATTLESHIP_SIZE 5
class Board
{
public:
	Ship **ships;	//:**param: it keeps board as a matrix
	int board_size;
	Board(std::vector<std::string>input_board = std::vector<std::string>());	//assuming that board is a square
	Status hit_ship(int x, int y, Ammunition ammo);
	void remove_ship(int x, int y);
	int count_ships();	//it returns number of remaining ships on board
	void incendiary_ships();
	void print_board();
};

