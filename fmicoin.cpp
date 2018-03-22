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
        listWallets();
        return 1;
    }
    std::cout << argv[1] << std::endl;

    if (strncmp(argv[1], addWalletCommand, strlen(addWalletCommand)) == 0)
    {
        unsigned walletid = addWallet(argc, argv);
        std::cout << "added: " << walletid << std::endl;
    }
    else if (strncmp(argv[1], walletInfoCommand, strlen(walletInfoCommand)) == 0)
    {
        int id = atoi(argv[2]);
        if (id == 0)
        {
            std::cout << "error: wallet id could not be parsed\n";
        }
        else
        {
            walletInfo(id);
        }
    }
    else
    {
        printUsage();
        listWallets();
        return 1;
    }
}