#pragma once
#include "Board.h"
#include<fstream>
#include<iostream>
#define MAX_BATTLESHIPS 2
#define MAX_NORMAL_SHIPS 6
#define BATTLESHIP_SIGN '#'
#define NORMAL_SHIP_SIGN '@'
#define BATTLESHIP_SIZE 5
std::vector<std::string> get_board(std::string file_name);
bool check_board(std::vector<std::string>board);