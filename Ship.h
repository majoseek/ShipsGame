#pragma once
#include<string>
class Ship
{
public:
	int health;
	std::string type;	//battleship or ... or ...
	int* effects;
	Ship(int start_health = 0, std::string in_type = "");

};

