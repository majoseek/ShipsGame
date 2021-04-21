#include "RecordedGame.h"
#include "Ammunition.h"
#include "Ranking.h"
#include "Functions.h"
#include <utility>
#include <sstream>


std::pair<int, int> operator-(const std::pair<int, int> a, const std::pair<int, int> b)
{
	return std::pair<int, int> {a.first - b.first, a.second - b.second};
}


RecordedGame::RecordedGame(const Game& game, std::string game_date) : Game(game), date(game_date)
{
	winner = next_player.name;
	std::pair<int, int> ammo = std::pair<int, int>{ 2*NORMAL_AMMO_QUANTITY, 2*INCENDIARY_AMMO_QUANTITY } - next_player.ammo - current_player.ammo;
	shots_fired = ammo.first + ammo.second;
	current_turn = 0;
	turns = current_player.logs.size();
}

std::string RecordedGame::player_turn()
{
	if (current_turn == turns)
		return "End of the game. Player " + next_player.name + " won\n" + game_stats();
	std::stringstream turn_outcome;
	if (current_turn < current_player.logs.size())
	{
		turn_outcome << current_turn + 1 << " turn. Player: " << current_player.name << "\n";
		turn_outcome << current_player.logs[current_turn] << "\n";
		
	}
	swap_player();
	if (current_turn < current_player.logs.size())
	{
		turn_outcome << current_turn + 1 << " turn. Player: " << current_player.name << "\n";
		turn_outcome << current_player.logs[current_turn];
		
	}
	swap_player();
	return turn_outcome.str();
}

std::string RecordedGame::game_stats() const
{
	std::stringstream stats;
	stats << "Game took " << turns << " turns. \n";
	stats << "There were " << shots_fired << " shots fired.\n";
	stats << "Player " << next_player.name << " won with " << next_player.remain_ships << " left.\n";
	stats << "Game was played on " << date;
	return stats.str();
}

void RecordedGame::add_ranking() const
{
	Ranking rank;
	get_ranking_from_file("Ranking.txt", rank);
	rank.list.push_back(std::make_pair(turns, date));
	std::sort(rank.list.begin(), rank.list.end(),
		[](auto& element1, auto& element2) {
			return element1.first < element2.first;
		});
	std::ofstream ranking("Ranking.txt");
	ranking << rank;
	ranking.close();
}
