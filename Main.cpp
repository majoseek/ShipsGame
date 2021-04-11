#include "Functions.h"
#include "Game.h"
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
	//Ammunition normal_ammo(5);
	//Incendiary incendiary_ammo(10);
	Player player1(player1_board.count_ships(), player1_board, b1.first);
	Player player2(player2_board.count_ships(), player2_board,b2.first);
	Game g1 = Game(player1, player2);
	while (!g1.check_game_end())
	{
		g1.current_player.player_board.print_board();
		std::cout << g1.current_player << endl << endl;
		std::cout << g1.player_turn() << endl;
		g1.swap_player();
		Sleep(2000);
		system("cls");
	}
	return 0;
}