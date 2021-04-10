#include "Functions.h"
#define MAX_BATTLESHIPS 2
#define MAX_NORMAL_SHIPS 6
#define BATTLESHIP_SIGN #
#define NORMAL_SHIP_SIGN @
using namespace std;

int main()
{
	vector<string>b = get_board("ship_PLAYER1.txt");
	if (b.empty())
		return 0;
	Board board(b);
	/*for (int i = 0; i < board.board_size; i++)
	{
		for (int j = 0; j < board.board_size; j++)
		{

		}
	}*/
	//	TODO: Make output operator (<<) for Ship Class
	return 0;
}