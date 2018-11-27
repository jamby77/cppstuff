#include <string>
#include <iostream>
#include "./monsters.h"

std::string monsterType(MonsterType t)
{

    if (t == MonsterType::Dragon)
    {
        return "Dragon";
    }

    if (t == MonsterType::Ogre)
    {
        return "Ogre";
    }

    if (t == MonsterType::Orc)
    {
        return "Orc";
    }

    if (t == MonsterType::GiantSpider)
    {
        return "GiantSpider";
    }

    if (t == MonsterType::Slime)
    {
        return "Slime";
    }
    return "Unknown monster";
}

void printMonster(Monster m)
{
    std::cout << "This " << monsterType(m.type) << " is named "
              << m.name << " and has " << m.health << " health." << '\n';
}