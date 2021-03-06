#include "Functions.h"
using namespace std;


int main()
{
	srand(time(NULL));
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
	Player player1, player2;
	if(b1.first=="Computer")
		player1=Computer(player1_board.count_ships(), player1_board, b1.first);
	else
		player1 = Player(player1_board.count_ships(), player1_board, b1.first);
	if (b1.first == "Computer")
		player2 = Computer(player2_board.count_ships(), player2_board, b2.first);
	else
		player2 = Player(player2_board.count_ships(), player2_board, b2.first);
	Game g1 = Game(player1, player2);
	while (!g1.check_game_end())
	{
		g1.current_player.player_board.print_board(cout);
		cout << g1.current_player << endl << endl;
		cout << g1.player_turn() << endl;
		g1.swap_player();
		system("pause");
		system("cls");
		save_game_to_file(g1);
	}
	cout << "Game ended!" << endl;
	cout << g1.next_player.name << " won. Congratulations!" << endl;
	play_recorder_game(g1);
	return 0;
}