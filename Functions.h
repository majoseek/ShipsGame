#pragma once
#include "Board.h"
#include "Player.h"
#include<fstream>
#include<iostream>
#include<utility>
#include "Game.h"
#include <iomanip>
std::pair<std::string,std::vector<std::string>> get_board(const std::string& file_name);
bool check_board(const std::vector<std::string>& board);
void print_file_error_msg();
void save_game_to_file(const Game& ended_game);