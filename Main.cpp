#include "Functions.h"
using namespace std;

int main()
{
	pair<string,vector<string>> b1 = get_board("ship_PLAYER1.txt");
	pair<string, vector<string>> b2 = get_board("ship_PLAYER2.txt");
	if (!check_board(b1.second) || !check_board(b2.second))
	{
		if (!check_board(b1.second))
			cout << "Please correct Player 1 board.\n";
		else if (!check_board(b2.second))
			cout << "Please correct Player 2 board.\n";
		print_file_error_msg();
		return 0;
	}
	Board player1_board(b1.second);
	Board player2_board(b2.second);
	Ammunition normal_ammo(5);
	Incendiary incendiary_ammo(10);
	Player player1(player1_board, b1.first, player1_board.count_ships(), 10,3);
	//Player player2(player2_board,b2.second,);

	return 0;
}