#include <iostream>
#include <fstream>
#include <string>
#include "./wallet.h"
#include "./helpers.h"
#include "./transacitons.h"

void writeWalletToFile(const Wallet &wallet, std::ofstream &ofs)
{
    ofs.write((const char *)&wallet, sizeof(Wallet));
}

void readWalletFromFile(Wallet &wallet, std::ifstream &ifs)
{
    ifs.read((char *)&wallet, sizeof(Wallet));
}

void outputWalletToStdout(const Wallet &wallet)
{
    std::cout << wallet.owner << std::endl;
}

void storeWallet(const Wallet &wallet)
{
    std::ofstream walletFile(WALLET_FILE_NAME, std::ios::binary | std::ios::app);
    if (walletFile.is_open())
    {
        writeWalletToFile(wallet, walletFile);
        outputWalletToStdout(wallet);
        std::cout << "Successfully added !" << std::endl;
        initialTransaction(wallet.id, wallet.fiatMoney);
    }
    else
    {
        std::cout << "error : while writing to the wallet data file";
    }

    walletFile.close();
}

void setWalletOwner(Wallet &wallet, const int argc, const char *argv[])
{
    size_t len;

    // pull out name
    for (size_t i = 3; i < argc; i++)
    {
        len = strlen(argv[i]) + 1;
        if (strlen(wallet.owner) + len > MAXN)
        {
            break;
        }

        if (strlen(wallet.owner))
        {
            // if part of name is already written add a space
            strncat(wallet.owner, " ", 1);
        }
        strncat(wallet.owner, argv[i], len);
    }
}

void addWallet(const int argc, const char *argv[])
{
    if (argc < 4)
    {
        // min 4 arguments expected: prog, command, amount, name
        std::cout << "Not enough arguments to add wallet" << std::endl;
        return;
    }

    Wallet wallet;
    wallet.fiatMoney = atof(argv[2]);
    wallet.id = nextId();
    setWalletOwner(wallet, argc, argv);

    storeWallet(wallet);
}
