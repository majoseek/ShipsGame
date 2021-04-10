#include "Player.h"
#include<fstream>
#pragma once
class Game
{
public:
	Player current_player;
	std::string* logs;	//:param[]: keeps history of made moves
	int hehe;
	bool check_game_end();
	void skip_turn();
	Game(Player starting_player);
};

