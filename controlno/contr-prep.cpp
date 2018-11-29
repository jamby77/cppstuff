#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

const double R = 1.0;
const double RX0 = 4;
const double RY0 = 2;

bool checkCircle(double x, double y)
{
    bool valid = true;
    double r = (x - RX0) * (x - RX0) + (y - RY0) * (y - RY0);
    valid = r >= 0 && r <= R * R;
    return valid;
}

const double RECTX0 = -2;
const double RECTY0 = 2;
const double RECTL = 4;
const double RECTW = 3;

bool checkRect(double x, double y)
{
    return (x >= RECTX0 - RECTL && x <= RECTX0) && (y >= RECTY0 && y <= RECTY0 + RECTW);
}

bool checkTri(double x, double y)
{
    const double X1 = 0;
    const double Y1 = -1;

    const double X2 = 6;
    const double Y2 = -2;

    const double X3 = -2;
    const double Y3 = -4;

    double eqGI = x * (Y1 - Y2) + y * (X2 - X1) + (X1 * Y2 - X2 * Y1);
    double eqGH = x * (Y3 - Y1) + y * (X1 - X3) + (X3 * Y1 - X1 * Y3);
    double eqHI = x * (Y3 - Y2) + y * (X2 - X3) + (X3 * Y2 - X2 * Y3);
    if (eqGI > 0 || eqGH > 0 || eqHI < 0)
    {
        return false;
    }
    return true;
}

void rotateInts(unsigned int N, unsigned int M)
{
    int nums[100];
    std::cout << "Enter " << N << " numbers" << '\n';
    for (unsigned int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    for (unsigned int i = 0; i < M; i++)
    {
        int t = nums[N - 1];
        for (unsigned int j = N - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = t;
    }

    for (unsigned int i = 0; i < N; i++)
    {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';
}

bool primeNumberSqrt(int a)
{
    if (a < 2)
    {
        return false;
    }
    for (int i = 2, c = sqrt(a); i <= c; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool primeNumberFull(int a)
{

    int count = 0;
    if (a < 2)
    {
        return false;
    }
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            count++;
        }
    }
    if (count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // std::cout << (int)sqrt(10) << '\n';

    // double x, y;
    // cout << "Enter x, y\n";
    // cin >> x >> y;
    // if (checkCircle(x, y))
    // {
    //     cout << "In circle\n";
    // }
    // else if (checkRect(x, y))
    // {
    //     cout << "In rectangle\n";
    // }
    // else if (checkTri(x, y))
    // {
    //     cout << "In triangle\n";
    // }
    // else
    // {
    //     cout << "Does not match any figure\n";
    // }
    std::clock_t start, full, sqr;
    start = std::clock();
    int t = 400000001;
    start = std::clock();
    primeNumberSqrt(t);
    sqr = std::clock();
    std::cout << "sqrt: " << (sqr - start) / (double)(CLOCKS_PER_SEC / 1000) << '\n';
    primeNumberFull(t);
    full = std::clock();
    std::cout << "full: " << (full - start) / (double)(CLOCKS_PER_SEC / 1000) << '\n';
    return 0;
}
