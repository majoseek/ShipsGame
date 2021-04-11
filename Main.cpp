#include "Functions.h"
using namespace std;

int main()
{
	vector<string>b = get_board("ship_PLAYER1.txt");
	if (b.empty())
		return 0;
	if (!check_board(b))
	{
		cout << "Please correct your board.\n" << "You can place maximum:\n" << MAX_NORMAL_SHIPS << " normal ships\n" << MAX_BATTLESHIPS << " battleships\n";
		return 0;
	}
	Board board(b);
	
	return 0;
}