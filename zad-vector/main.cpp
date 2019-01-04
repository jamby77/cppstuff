#include <cstdio>
#include <iostream>

int main()
{
    char vecotr[100];
    int a, b, c;
    char v;

    std::cout << "Enter vector" << '\n';
    std::cin.getline(vecotr, 100);

    std::cout << sscanf(vecotr, "%c(%d,%d,%d)", &v, &a, &b, &c) << " scanned\n";

    std::cout << vecotr << '\n';
    std::cout << v << '\n';
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    return 0;
}