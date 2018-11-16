#include <iostream>
const int MAX = 10000;
int isPrime(int n)
{

    if (n == 0 || n == 1)
    {
        return 0;
    }

    if (n == 2 || n == 3)
    {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return 0;
    }

    int i = 5;
    int w = 2;

    while (i * i < n)
    {

        if (n % i == 0)
        {
            return 0;
        }
        i += w;
        w = 6 - w;
    }
    return 1;
}

int main()
{
    int nums[MAX];
    int n;

    std::cin >> n;

    std::cout << n << "\n";

    for (int i = 0; i < n; i++)
    {
        nums[i] = isPrime(i);
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << i;
        if (nums[i] == 1)
        {
            std::cout << " - is Prime" << '\n';
        }
        else
        {
            std::cout << " - is Not Prime" << '\n';
        }
    }
    return 0;
}
