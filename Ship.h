#pragma once
#include<string>

class Ship
{
public:
	int health;
	std::string type;	//battleship or ... or ...
	int hit_incendiary;
	Ship(int start_health = 0);
	void take_damage(int amount);
	bool is_destroyed() { return health <= 0; }
};

