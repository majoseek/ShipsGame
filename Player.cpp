#include "Player.h"
#include "Status.h"
#include <ostream>
Player::Player(const int& start_ships, const Board& p_board, const std::string& in_name)
{
	name = in_name;
	ammo = std::make_pair(NORMAL_AMMO_QUANTITY, INCENDIARY_AMMO_QUANTITY);
	player_board = p_board;
	remain_ships = start_ships;
}


std::string Player::take_shot(const int& x, const int& y, const Ammunition& shoot_ammo,Player& shooter)
// Method used to combat between two players 
{
	Status hit_status = player_board.hit_ship(x, y, shoot_ammo);
	std::string shot_msg;
	if (hit_status == Status::Destroyed)
	{
		shot_msg = " destroyed the ship!";
	}
	if (hit_status == Status::Miss)
	{
		shot_msg = " missed!";
	}
	else
		shot_msg = " hit the ship!";
	char x_tmp = 'A' + x;
	std::string log_msg = shooter.name + " shoots on area " + x_tmp + std::to_string(y+1) + " with " + shoot_ammo.type + " ammo\n";
	log_msg += shooter.name+shot_msg;
	shooter.logs.push_back(log_msg);
	if (shooter.name == "Computer")
		return log_msg;
	return "You"+shot_msg;
}


std::ostream& operator<<(std::ostream& os, const Player& player)
{
	os << player.name << "'s turn. \nYou have " << player.ammo.first << " normal ammunition left and ";
	os << player.ammo.second << " incendiary ammunition left." << std::endl;
	os << "You still have " << player.player_board.count_ships() << " ships left.";
	return os;
}
std::pair<int, int> Player::rand_area(int& ammo_type)
{
	char target_letter;
	std::vector<char>allowed_letters;
	char starting_char = 'A';
	for (int i = 0; i < player_board.board_size; i++, starting_char++)
		allowed_letters.push_back(starting_char);
	target_letter = allowed_letters[rand() % allowed_letters.size()];
	int target_num = rand() % player_board.board_size + 1;
	std::cout << target_letter << " " << target_num << "\n";
	std::pair<int, int>target = std::make_pair(target_letter - 'A', target_num - 1);
	if (ammo.first > 0 && ammo.second > 0)
		ammo_type = rand() % 2;
	else if (ammo.first > 0)
		ammo_type = 0;
	else
		ammo_type = 1;
	return target;
}