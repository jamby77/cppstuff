#include "./monsters.h"

int main(int argc, char const *argv[])
{
    Monster ogre{"Torg", MonsterType::Ogre, 145};
    Monster slime{"Blurp", MonsterType::Slime, 23};

    printMonster(ogre);
    printMonster(slime);

    return 0;
}
