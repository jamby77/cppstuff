#include <iostream>
#include <cstring>
const char *ints[26] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26"};
int main()
{
    short capDiff = 'a' - 'A';
    // std::cout << ('a' - ' ') << '\n';
    // std::cout << (int)'9' << '\n';
    char text[1000] = "ala bala nica";
    char t = text[0];
    short cnt = 0;
    for (size_t i = 0; t != '\0'; i++)
    {
        t = text[i];
        if (t > 'z' || t == ' ' || t < 'A')
        {
            std::cout << t;
            cnt++;
            continue;
        }

        if (t >= 'A' && t <= 'Z')
        {
            t = (t + capDiff);
        }
        int idx = t - 'a';
        const char *repl = ints[idx];
        std::cout << repl;
    }

    std::cout << " - " << cnt << " dumi\n";
    return 0;
}