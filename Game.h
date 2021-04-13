#include "Player.h"
#include<fstream>
#include <string>
#include <iostream>
#include <algorithm>
#pragma once
class Game
{
public:
	Player current_player;
	Player next_player;
	bool check_game_end() const;
	std::string player_turn();
	Game(Player starting_player, Player second_player);
	void swap_player();
};

