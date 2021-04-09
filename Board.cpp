#include "Board.h"
Board::Board(char** input_board, int board_size)
{
	ships = new Ship * [board_size];	//allocating memory of board size
	for (int i = 0; i < board_size; i++)
		ships[i] = new Ship[board_size];

	for(int i=0;i<board_size;i++)
		for (int j = 0; j < board_size; j++)
		{
			ships[i][j] = input_board[i][j];	//copying user input to class matrix
		}
}