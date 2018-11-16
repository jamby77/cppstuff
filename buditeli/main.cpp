#include <iostream>
#include <cstring>
int main()
{
    const int LEN = 10;
    const size_t MAX_LEN = 50;
    const char *buditeli[] = {
        "Kiril i Metodi",
        "Ivan Vazov",
        "Ivan Vazov",
        "Ivan Vazov",
        "Ivan Vazov",
        "Ivan Vazov",
        "Ivan Vazov",
        "Ivan Vazov",
        "Ivan Vazov",
        "Ivan Vazov",
    };

    char attempt[MAX_LEN];

    std::cin.getline(attempt, MAX_LEN);
    std::cout << attempt << '\n';

    for (size_t i = 0; i < LEN; i++)
    {
        if (strncmp(buditeli[i], attempt, MAX_LEN) == 0)
        {
            std::cout << "Yeeeeee" << '\n';
            return 0;
        }
    }

    std::cout << "No match, So sad" << '\n';

    return 0;
}
