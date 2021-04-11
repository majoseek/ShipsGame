#include "Functions.h"
using namespace std;

pair<string,vector<string>> get_board(string file_name)
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
bool check_board(vector<string>board)
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
	for (int i = 0; i < 50; i++)
		cout << "=";
	cout << "\nYou can place maximum:\n" << MAX_NORMAL_SHIPS << " normal ships\n" << MAX_BATTLESHIPS << " battleships\n";
	cout << "Normal ships are marked as " << NORMAL_SHIP_SIGN << endl;
	cout << "Battleships are marked as " << BATTLESHIP_SIGN << endl;
	cout << "Empty areas are marked as -" << endl;
	for (int i = 0; i < 50; i++)
		cout << "=";
}