#include <iostream>

int readNumber();

void writeAnswer(int answer);

int main()
{
    int a = readNumber();
    int b = readNumber();

    writeAnswer(a + b);
    return 0;
}

int readNumber()
{
    int number;

    std::cin >> number;

    return number;
}

void writeAnswer(int answer)
{
    std::cout << "The answer is: " << answer << std::endl;
}