#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    cout << "argc is: " << argc << endl;
    for (size_t i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }

    if (argc < 4)
    {
        cout << "Not enough arguments" << endl;
        return 1;
    }
}