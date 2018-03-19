#include <iostream>
#include <string>

using namespace std;
void toBin(int n)
{
    if (n == 0 || n == 1)
    {
        cout << n;
        return;
    }
    int a[64] = {0}, i;

    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }

    for (i = i - 1; i >= 0; i--)
    {
        cout << a[i];
    }
}

void outputNumInBin(string msg, int n)
{
    cout << msg;

    toBin(n);
    cout << endl;
}

int main()
{
    unsigned int x = 25;
    unsigned int mask = 1;
    unsigned int n = 3;

    outputNumInBin("mask: ", (mask << n));
    outputNumInBin("x:    ", x);
    outputNumInBin("N bit is: ", ((x & (mask << n)) >> n));
    return 0;
}