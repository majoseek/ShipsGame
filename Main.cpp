#include "Functions.h"
#include "Game.h"
#include <fstream>
#include <iomanip>
using namespace std;

void save_game_to_file(Game ended_game)
{
	ofstream player1_file("player1_game.txt");
	player1_file << "Player: " << setw(10) << ended_game.current_player.name << endl;
	player1_file << setfill('=') << setw(50) << "" << endl;
	ended_game.current_player.player_board.print_board(player1_file);
	player1_file << setfill('=') << setw(50) << "" << endl;
	// Add logs for teh player 1 
	player1_file.close();
	ofstream player2_file("player2_game.txt");
	player2_file << "Player: " << setw(10) << ended_game.current_player.name << endl;
	player2_file << setfill('=') << setw(50) << "" << endl;
	ended_game.current_player.player_board.print_board(player2_file);
	player2_file << setfill('=') << setw(50) << "" << endl;
	// Add logs for the player 2
	player2_file.close();
}

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
		g1.current_player.player_board.print_board(cout);
		std::cout << g1.current_player << endl << endl;
		std::cout << g1.player_turn() << endl;
		g1.swap_player();
		system("pause");
		system("cls");
	}
	std::cout << "Game ended!" << endl;
	std::cout << g1.next_player.name << " won. Congratulation!";
	save_game_to_file(g1);
	return 0;
}