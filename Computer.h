#pragma once
#include "Player.h"
class Computer :
    public Player
{
public:
    Computer(const int& starting_ships = 0, const Board& p_board = Board(std::vector<std::string>()), const std::string& in_name = "");
};

