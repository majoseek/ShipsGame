#include "Computer.h"
Computer::Computer(const int& starting_ships, const Board& p_board,const std::string& in_name) : Player(starting_ships,p_board,in_name)
{
	name = "Computer";
}