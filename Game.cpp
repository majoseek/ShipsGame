#include "Game.h"
#include "Incendiary.h"
#include <cstdlib>
#include<stdlib.h>
#include<time.h>

bool check_range(const int& a, const int& b, const int& num)
// Simple function to check whether a num is in the range <a, b>
{
	return (num >= a && num <= b);
}


std::pair<int, int> get_player_target(const int& board_size)
// Function which gets a target cell input from the player
{
	int target_num;
	char target_letter;
	std::cout << "Type a cell to attack(eg: A1): ";
	std::cin >> target_letter >> target_num;
	while (!check_range('A', 'A' + board_size - 1, target_letter) || !check_range(1, board_size, target_num))
	{
		std::cout << "Incorrect cell. Provide it again: ";
		std::cin >> target_letter >> target_num;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return std::make_pair(target_letter - 'A', target_num - 1);
}

int get_ammo_type(const std::pair<int, int>& ammo_left)
// Function which gets an ammuntion type from the player
{
	std::string ammo_kind;
	std::cout << "Type an ammuntion kind - N (Normal), I (Incendiary):";
	std::cin >> ammo_kind;
	bool condition = true;
	for (auto& c : ammo_kind) c = toupper(c);
	if (ammo_kind == "N" && ammo_left.first > 0)
	{
		condition = false;
	}
	else if (ammo_kind == "I" && ammo_left.second > 0)
	{
		condition = false;
	}
	while (condition)
	{
		std::cout << "Incorrect ammunation type. Provide it again: ";
		std::cin >> ammo_kind;
		for (auto& c : ammo_kind) c = toupper(c);
		if (ammo_kind == "N" && ammo_left.first > 0)
		{
			condition = false;
		}
		else if (ammo_kind == "I" && ammo_left.second > 0)
		{
			condition = false;
		}
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (ammo_kind == "N")
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


bool Game::check_game_end() const
// Returns true when the game is ended(either no ships or ammo)
{
	if (current_player.player_board.count_ships() == 0)
	{
		return true;
	}
	if (!current_player.has_ammo() && !next_player.has_ammo())
	{
		return true;
	}
	return false;
}

std::string Game::player_turn()
// Plays a turn and returns an outcome messages
{
	next_player.player_board.incendiary_ships();
	if (!(current_player.has_ammo()))
	{
		return "You ran out of the ammuntion! Proceeding to the next player.";
	}
	int ammo_type = 0;
	std::pair<int, int> target;
	if (current_player.name != "Computer")
	{
		target = get_player_target(current_player.player_board.board_size);
		ammo_type=get_ammo_type(current_player.ammo);
	}
	else
	{
		char target_letter;
		std::vector<char>allowed_letters;
		char starting_char = 'A';
		for (int i = 0; i < current_player.player_board.board_size; i++, starting_char++)
			allowed_letters.push_back(starting_char);
		target_letter = allowed_letters[rand()%allowed_letters.size()];
		int target_num = rand() % current_player.player_board.board_size + 1;
		std::cout << target_letter << " " << target_num << "\n";
		target=std::make_pair(target_letter - 'A', target_num - 1);
		if (current_player.ammo.first > 0 && current_player.ammo.second > 0)
			ammo_type = rand() % 2;
		else if (current_player.ammo.first > 0)
			ammo_type = 0;
		else
			ammo_type = 1;

	}
	if (ammo_type == 0)
	{
		current_player.ammo.first--;
		return next_player.take_shot(target.first, target.second, Ammunition(NORMAL_AMMO_DMG),current_player.name);
	}
	current_player.ammo.second--;
	return next_player.take_shot(target.first, target.second, Incendiary(INCENDIARY_AMMO_DMG),current_player.name);
}

Game::Game(Player starting_player, Player second_player)
{
	current_player = starting_player;
	next_player = second_player;
}

void Game::swap_player()
{
	std::swap(current_player, next_player);
}
