#include "Functions.h"
using namespace std;

vector<string> get_board(string file_name)
{
	auto size_error = []()
	{
		cout << "Board must be a square!" << endl;
	};
	vector<string>board_o;
	int board_size = NULL;
	int previous_line_size = NULL;
	bool first_line = true;
	int line_count = 0;
	fstream file;
	file.open(file_name);
	if (file.good())
	{
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
					return vector<string>();
				}
			}
			previous_line_size = board_size;
		}
		if (board_size != line_count)
		{
			size_error();
			return vector<string>();
		}
	}
	else
	{
		cout << "Please check if your file exists." << endl;
	}
	return board_o;
}
bool check_board(vector<string>board)
{
	int battleship_number=0, normal_ship_number = 0;
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == BATTLESHIP_SIGN)
				battleship_number++;
			else if (board[i][j] == NORMAL_SHIP_SIGN)
				normal_ship_number++;
			else if (board[i][j] != '-')
				return false;	//This square got wrong identity
		}
	if (battleship_number > MAX_BATTLESHIPS || normal_ship_number > MAX_NORMAL_SHIPS)
		return false;
	return true;
}