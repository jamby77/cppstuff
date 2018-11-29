#include <iostream>
using namespace std;

const unsigned int MAX = 100;

int main()
{

    unsigned int N = 9;
    unsigned int length = 0;
    int A[MAX] = {1, 2, -3, 1, 2, -3, 1, 2, -3};
    int helper[MAX];

    // cout << "N=";
    // cin >> N;
    // while (N > 100)
    // {
    //     cout << "Your number should be less than 100";
    //     cin >> N;
    // }

    int *a = A;
    int *h = helper;
    *h = *a;

    // for (unsigned int i = 0; i < N; i++)
    // {
    //     a += i;
    //     cin >> *a;
    // }

    for (unsigned int i = 1; i <= N; i++)
    {

        if (*a != *a + static_cast<int>(i))
        {
            *(h + i) = *(a + i);
            length++;
        }
        else
        {
            break;
        }
    }

    for (unsigned int i = 0; i < length; i++)
    {
        cout << helper[i];
    }

    return 0;
}