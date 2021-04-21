#include "Functions.h"
#include <ctime>
#include <chrono>
using namespace std;

pair<string,vector<string>> get_board(const string& file_name)
// Function which gets player's data from a file. Returns pair of <player_name, player_board>
{
	auto size_error = []()
	{
		cout << "Board must be a square!" << endl;
	};
	vector<string>board_o;
	pair<string, vector<string>>result;
	int board_size = NULL;
	int previous_line_size = NULL;
	bool first_line = true;
	int line_count = 0;
	fstream file;
	file.open(file_name);
	if (file.good())
	{
		string p_name;
		getline(file, p_name);
		result.first = p_name;
		while (!file.eof())
		{
			string line;
			getline(file, line);
			board_o.push_back(line);
			line_count++;
			board_size = line.length();
			if (first_line)
			{
				first_line = false;
			}
			else
			{
				if (board_size != previous_line_size)
				{
					size_error();
					pair<string,vector<string>>error_pair = make_pair("", vector<string>());
					return error_pair;
				}
			}
			previous_line_size = board_size;
		}
		if (board_size != line_count)
		{
			size_error();
			pair<string, vector<string>>error_pair = make_pair("", vector<string>());
			return error_pair;
		}
	}
	else
	{
		cout << "Please check if file " <<file_name<<" exists." << endl;
	}
	result.second = board_o;
	return result;
}
bool check_board(const vector<string>& board)
// Function which checks booard's correctness
{
	if (board.empty())
		return false;
	int battleship_number=0, normal_ship_number = 0;
	for (auto line: board)
		for (auto area:line)
		{
			if (area == BATTLESHIP_SIGN)
				battleship_number++;
			else if (area == NORMAL_SHIP_SIGN)
				normal_ship_number++;
			else if (area != '-')
				return false;	//This square got wrong identity
		}
	if (battleship_number > MAX_BATTLESHIPS || normal_ship_number > MAX_NORMAL_SHIPS)
		return false;
	return true;
}
void print_file_error_msg()
{
	// Function which outputs an error message
	for (int i = 0; i < 50; i++)
		cout << "=";
	cout << "\nFirst line must contain your name" << endl;
	cout << "You can place maximum:\n" << MAX_NORMAL_SHIPS << " normal ships\n" << MAX_BATTLESHIPS << " battleships\n";
	cout << "Normal ships are marked as " << NORMAL_SHIP_SIGN << endl;
	cout << "Battleships are marked as " << BATTLESHIP_SIGN << endl;
	cout << "Empty areas are marked as -" << endl;
	for (int i = 0; i < 50; i++)
		cout << "=";
}
void save_game_to_file(const Game& ended_game)
// Function which saves info about ended_game to a file
{
	ofstream player1_file("player1_game.txt");
	player1_file << "Player: " << setw(10) << ended_game.current_player.name << endl;
	player1_file << setfill('=') << setw(50) << "" << endl;
	ended_game.current_player.player_board.print_board(player1_file);
	player1_file << setfill('=') << setw(50) << "" << endl;
	for (auto log : ended_game.current_player.logs)
		player1_file << log << endl;
	player1_file.close();
	ofstream player2_file("player2_game.txt");
	player2_file << "Player: " << setw(10) << ended_game.next_player.name << endl;
	player2_file << setfill('=') << setw(50) << "" << endl;
	ended_game.next_player.player_board.print_board(player2_file);
	player2_file << setfill('=') << setw(50) << "" << endl;
	for (auto log : ended_game.next_player.logs)
		player2_file << log << endl;
	player2_file.close();
}
void play_recorder_game(const Game& game_ended)
{
	std::time_t now = time(0);
	char buff[20]{};
	struct tm buf;
	errno_t err = localtime_s(&buf, &now);
	std::strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M", &buf);
	RecordedGame game = RecordedGame(game_ended, std::string(buff));
	game.add_ranking();
	char action = ' ';
	std::cout << "Do you want to get to inspect last game? (type I to inspect): ";
	std::cin >> action;
	action = std::toupper(action);
	if (action != 'I')
		return;
	std::cout << "Playing last game" << std::endl;
	std::cout << "Use 'A' and 'D' to move to next or previous turn. Use 'q' to exit" << std::endl;
	while (action != 'Q')
	{
		std::cout << game.player_turn() << std::endl;
		std::cin >> action;
		action = std::toupper(action);
		switch (action)
		{
		case 'A':
			if (game.current_turn > 0)
			{
				--game.current_turn;
			}
			system("cls");
			break;
		case 'D':
			if (game.current_turn < game.turns)
			{
				++game.current_turn;
			}
			system("cls");
			break;
		case 'Q':
			break;
		default:
			break;
		}
	}
	std::cout << game.game_stats() << std::endl;
}

void get_ranking_from_file(std::string file_name, Ranking& ranking)
{
	std::ifstream rank_file(file_name);
	std::string line;
	std::getline(rank_file, line);
		line.erase(std::remove(line.begin(), line.end(), '='), line.end());
	ranking.category = line;
	int place;
	std::string date;
	std::string time;
	int turns;
	while (rank_file >> place)
	{
		rank_file >> date >> time >> turns;
		date += (" " + time);
		ranking.list.push_back(std::make_pair(turns, date));
	}
	rank_file.close();
}
