#pragma once
#include "Game.h"
class RecordedGame : public Game
{
	
public:
	std::string winner;
	int shots_fired;
	int turns;
	std::string date;
	int current_turn;
	RecordedGame(const Game& game, std::string date);
	std::string player_turn();
	std::string game_stats() const;
	void add_ranking() const;
};

