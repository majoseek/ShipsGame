#pragma once
#include "Board.h"
#include "Player.h"
#include "Computer.h"
#include "RecordedGame.h"
#include "Ranking.h"
#include<fstream>
#include<iostream>
#include<utility>
#include <iomanip>
std::pair<std::string,std::vector<std::string>> get_board(const std::string& file_name);
bool check_board(const std::vector<std::string>& board);
void print_file_error_msg();
void save_game_to_file(const Game& ended_game);
void play_recorder_game(const Game& game);
void get_ranking_from_file(std::string file_name, Ranking& ranking);