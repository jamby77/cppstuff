#include <iostream>
#include <cstring>
#include "helpers.h"
#include "wallet.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // no arguments are passed to the program, this is error
        printUsage();
        listWallets();
        return 1;
    }

    if (strncmp(argv[1], ADD_WALLET_COMMAND, strlen(ADD_WALLET_COMMAND)) == 0) {
        unsigned walletid = addWallet(argc, argv);
        std::cout << "added: " << walletid << std::endl;
    } else if (strncmp(argv[1], WALLET_INFO_COMMAND, strlen(WALLET_INFO_COMMAND)) == 0) {
        auto id = static_cast<unsigned int>(strtol(argv[2], nullptr, 10));
        if (id == 0) {
            std::cout << "error: wallet id could not be parsed\n";
        } else {
            walletInfo(id);
        }
    } else {
        printUsage();
        listWallets();
        return 1;
    }
}
