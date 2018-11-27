#include <iostream>
#include "./races.h"

int main()
{
    Races troll(Races::RACE_TROLLS);

    std::cout << static_cast<int>(troll) << '\n';
    return 0;
}
