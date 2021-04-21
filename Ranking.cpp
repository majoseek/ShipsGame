#include "Ranking.h"
#include <iomanip>
#include <fstream>


std::ostream& operator<<(std::ostream& os, const Ranking& ranking)
{
    os << "=======" <<  ranking.category << "=======" << std::endl;
    for (int i = 0; i < ranking.list.size(); ++i)
    {
        os << i+1  << "\t" << ranking.list[i].second << " " << ranking.list[i].first << std::endl;
    }
    return os;
}


