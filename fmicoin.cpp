#include <iostream>
#include <string.h>
#include "helpers.h"
#include "wallet.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        // no arguments are passed to the program, this is error
        printUsage();
        return 1;
    }

    if (strncmp(argv[1], addWalletCommand, strlen(addWalletCommand)) == 0)
    {
        addWallet(argc, argv);
    }
    else
    {
        printUsage();
        return 1;
    }
}