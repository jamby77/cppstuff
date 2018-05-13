#include <iostream>

int readNumber()
{
    std::cout << "Enter a number: ";
    int number;

    std::cin >> number;

    return number;
}

void writeAnswer(int answer)
{
    std::cout << "The answer is: " << answer << std::endl;
}