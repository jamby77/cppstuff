#include "io.h"

int main()
{
    int a = readNumber();
    int b = readNumber();

    writeAnswer(a + b);
    return 0;
}