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