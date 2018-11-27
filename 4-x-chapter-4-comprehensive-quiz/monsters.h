#ifndef H_MONSTERS
#define H_MONSTERS
#include <string>

using health_t = int;

enum class MonsterType
{
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime,
};

struct Monster
{
    std::string name;
    MonsterType type;
    health_t health;
};

void printMonster(Monster m);

#endif // !H_MONSTERS