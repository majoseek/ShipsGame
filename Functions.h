#pragma once
#include "Board.h"
#include "Player.h"
#include<fstream>
#include<iostream>
#include<utility>
std::pair<std::string,std::vector<std::string>> get_board(std::string file_name);
bool check_board(std::vector<std::string>board);
void print_file_error_msg();