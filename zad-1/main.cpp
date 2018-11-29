#include <iostream>
#include <cstring>

const int MAX_NAMES = 100;

int main()
{
    int n; //broi imena
    char *names[MAX_NAMES]; // masiv imena
    int numNames[MAX_NAMES]; // masiv broyach

    std::cin >> n;
    if (n >= MAX_NAMES)
    {
        std::cout << "Max supported number of names is 99" << '\n';
        return 1;
    }
    std::cin.ignore(32767, '\n'); // clear (up to 32767) characters out of the buffer until a '\n' character is removed

    for (int i = 0; i < n; i++)
    {
        char *temp = new char;
        std::cin.getline(temp, MAX_NAMES);               // just use max names as limit for everything
        names[i] = temp;
        numNames[i] = 0;                                     // initialize name counter
    }

    int j = 0, m = 0;

    for (int i = 0; i < n; i++)
    {
        char *t = names[i];
        numNames[i]++;
        for (int k = 0; k < n; k++)
        {
            if (k == i)
            {
                continue;
            }
            if (strcmp(t, names[k]) == 0)
            {
                numNames[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (numNames[i] > m)
        {
            m = numNames[i];
            j = i;
        }
    }
    std::cout << names[j] << ':' << m << '\n';
    return 0;
}
