#pragma once
#include "RecordedGame.h"

typedef std::vector<std::pair<int, std::string>> rankingList;

class Ranking
{
public:
	Ranking(std::string cat="") : category(cat) {};
	std::string category;
	rankingList list;
};

std::ostream& operator<<(std::ostream& os, const Ranking& ranking);
