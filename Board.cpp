#include "Board.h"
#include"Battleship.h"
#include<iostream>
Board::Board(std::vector<std::string> input_board)
{
	int b_size = input_board.size();
	ships = new Ship * [b_size];	//allocating memory of board size
	for (int i = 0; i < b_size; i++)
		ships[i] = new Ship[b_size];

	for(int i=0;i< b_size;i++)
		for (int j = 0; j < b_size; j++)
		{
			if (input_board[i][j] == BATTLESHIP_SIGN)
				ships[i][j] = Battleship(30, 10);	//(health,armor)
			else if (input_board[i][j] == NORMAL_SHIP_SIGN)
				ships[i][j] = Ship(15);	//(health)
			else
				ships[i][j] = Ship(0);	//empty area

		}
	board_size = b_size;
}
int Board::count_ships()
{
	int result = 0;
	for(int i=0;i<board_size;i++)
		for (int j = 0; j < board_size; j++)
		{
			if (ships[i][j].health>0)
				result++;
		}
	return result;
}

void Board::incendiary_ships()
{
	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
		{
			if (ships[i][j].hit_incendiary > 0)
			{
				ships[i][j].take_damage(INCENDIARYDMG);
				ships[i][j].hit_incendiary--;
			}
				
		}
}

Status Board::hit_ship(int x, int y, Ammunition ammo)
{
	if (ships[x][y].is_destroyed())
	{
		return Status::Miss;
	}
	else
	{
		ships[x][y].take_damage(ammo.damage);
		if (ammo.type == "INCENDIARY")
			ships[x][y].hit_incendiary = 3;
		if (ships[x][y].is_destroyed())
		{
			remove_ship(x, y);
			return Status::Destroyed;
		}
		return Status::Hit;
	}
}

void Board::remove_ship(int x, int y)
{
	ships[x][y].type = "NONE";
	ships[x][y].health = 0;
	ships[x][y].hit_incendiary = 0;
}