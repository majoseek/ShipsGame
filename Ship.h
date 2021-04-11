#pragma once
#include<string>
#define max(a,b) ((a)>(b)?(a):(b))
class Ship
{
public:
	int health;
	std::string type;	//battleship or ... or ...
	int* effects;
	Ship(int start_health = 0);
	void take_damage(int amount);
};

