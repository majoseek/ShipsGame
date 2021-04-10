#include "Board.h"
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
			ships[i][j] = Ship(10, "RODZAJ_STATKU");
		}
	board_size = b_size;
}