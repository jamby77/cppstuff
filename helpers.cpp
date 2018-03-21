#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include "helpers.h"

void printUsage()
{
    std::cout
        << "usage: (add-wallet|make-order|make-transaction) (amount) (name|walletid)"
        << std::endl;
}

unsigned int timeid()
{
    time_t now;
    struct tm epoch = {0};
    double seconds;
    time(&now);

    epoch = *localtime(&now);
    epoch.tm_hour = 0;
    epoch.tm_min = 0;
    epoch.tm_sec = 0;
    epoch.tm_mon = 0;
    epoch.tm_mday = 1;
    epoch.tm_year = 70;

    seconds = difftime(now, mktime(&epoch));
    return (unsigned)seconds;
}

int nextId()
{
    int id;
    std::ifstream inIdFile("id.bin", std::ios::binary);
    if (!inIdFile.is_open())
    {
        std::cout << "Can't open file for reading" << '\n';
    }
    else
    {
        inIdFile.seekg(0, std::ios::beg);
        inIdFile.read((char *)&id, sizeof(int));
        id++;
        inIdFile.close();
    }
    std::ofstream outIdFile("id.bin", std::ios::trunc | std::ios::binary);

    if (!outIdFile.is_open())
    {
        std::cout << "Can't open file for writing" << '\n';
    }
    else
    {
        outIdFile.write((char *)&id, sizeof(int));
    }

    return id;
}