#include <iostream>
#include <fstream> // std::ifstream, std::ofstream
using namespace std;
int nextId()
{
    int id;
    ifstream inIdFile("id.bin", ios::binary);
    if (!inIdFile.is_open())
    {
        cout << "Can't open file for reading" << '\n';
    }
    else
    {
        inIdFile.seekg(0, ios::beg);
        inIdFile.read((char *)&id, sizeof(int));
        id++;
        inIdFile.close();
    }
    ofstream outIdFile("id.bin", ios::trunc | ios::binary);
    if (!outIdFile.is_open())
    {
        cout << "Can't open file for writing" << '\n';
    }
    else
    {
        outIdFile.write((char *)&id, sizeof(int));
    }

    return id;
}
int main()
{
    int N, num, res;
    streampos size;
    ofstream outfile("new.txt", ios::out | ios::binary);
    if (!outfile.is_open())
    {
        cout << "Can't open file for writing" << '\n';
    }

    cout << "how many numbers do you want?" << endl;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        outfile.write((char *)&num, sizeof(int));
    }

    outfile.close();

    ifstream file("new.txt", ios::in | ios::binary | ios::ate);
    size = sizeof(num);

    if (file.is_open())
    {
        file.seekg(0, ios::beg);
        for (int i = 0; i < N; i++)
        {
            if ((i + 1) % 3 != 0)
            {
                continue;
            }
            file.seekg(i * size, ios::beg);
            file.read((char *)&res, size);
            cout << res << endl;
        }
        file.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}