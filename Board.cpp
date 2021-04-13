#include "Board.h"
#include"Battleship.h"
#include<iostream>
using namespace std;
Board::Board(vector<string> input_board)
{
	int b_size = input_board.size();
	ships = new Ship * [b_size];	//allocating memory of board size
	for (int i = 0; i < b_size; i++)
		ships[i] = new Ship[b_size];

	for(int i=0;i< b_size;i++)
		for (int j = 0; j < b_size; j++)
		{
			if (input_board[i][j] == BATTLESHIP_SIGN)
				ships[i][j] = Battleship(BATTLESHIP_HEALTH, BATTLESHIP_ARMOR);	//(health,armor)
			else if (input_board[i][j] == NORMAL_SHIP_SIGN)
				ships[i][j] = Ship(NORMALSHIP_HEALTH);	//(health)
			else
			{
				ships[i][j] = Ship(0);	//empty area
				ships[i][j].type = "NONE";
			}

		}
	board_size = b_size;
}
int Board::count_ships() const
// Method which counts not destroyed ships on the board
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
// Method which burns with incendiary effect all the hit ships 
{
	for (int i = 0; i < board_size; i++)
		for (int j = 0; j < board_size; j++)
		{
			if (ships[i][j].hit_incendiary > 0)
			{
				ships[i][j].take_damage(INCENDIARYDMG);
				ships[i][j].hit_incendiary--;
				if (ships[i][j].is_destroyed())
				{
					remove_ship(i, j);
				}
			}
				
		}
}

Status Board::hit_ship(const int& x, const int& y, const Ammunition& ammo)
// Method which allows hitting ships
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

void Board::remove_ship(const int& x, const int& y)
// Method which removes a destroyed ship situated at XY
{
	ships[x][y].type = "NONE";
	ships[x][y].health = 0;
	ships[x][y].hit_incendiary = 0;
}
void Board::print_board(std::ostream& os) const
// Simple method to print the current state of the board
{
	for (int i = 0; i < board_size*2+2; i++)
		os << "=";
	os << "\n";
	char sign = 'A';
	for (int i = 0; i < board_size; i++,sign++)
	{
		os << sign << " ";
		for (int j = 0; j < board_size; j++)
		{
			if (ships[i][j].type == "BATTLESHIP")
				os << " #";
			else if (ships[i][j].type == "NORMAL")
				os << " @";
			else
				os << " -";
		}
		os << endl;
	}
	for (int i = 0; i < 3; i++)
		os << " ";
	for (int i = 0; i < board_size; i++)
		os << i+1 << " ";
	os << endl;
	for (int i = 0; i < board_size*2+2; i++)
		os << "=";
	os << "\n";

}