#include <iostream>
#include <fstream>
#include <string.h>
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
        initialTransaction(wallet.id, wallet.fiatMoney);
    }
    else
    {
        std::cout << "error : while writing to the wallet data file";
    }

    walletFile.close();
}

void setWalletOwner(Wallet &wallet, int argc, char *argv[])
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

unsigned addWallet(int argc, char *argv[])
{
    if (argc < 4)
    {
        // min 4 arguments expected: prog, command, amount, name
        std::cout << "Not enough arguments to add wallet" << std::endl;
        exit(1);
    }

    Wallet wallet;
    wallet.fiatMoney = atof(argv[2]);
    wallet.id = nextId();
    setWalletOwner(wallet, argc, argv);

    storeWallet(wallet);
    return wallet.id;
}

int countWallets(std ::ifstream &fs)
{
    int length;
    fs.seekg(0, std::ios::end);
    length = fs.tellg();
    fs.seekg(0, std::ios::beg);
    return length / sizeof(Wallet);
}

Wallet *loadWallets(int wc, std::ifstream &fs)
{
    Wallet *ws = new (std::nothrow) Wallet[wc];
    if (ws == nullptr)
    {
        std::cout << "error: not enough memory to load wallets\n";
        return nullptr;
    }
    // read all wallets into array
    fs.read((char *)ws, sizeof(Wallet) * wc);

    if (!fs)
    {
        std::cout << "error : while reading the database! \n";
        delete[] ws;
        return nullptr;
    }
    return ws;
}

void listWallets()
{
    std::ifstream walletFile(WALLET_FILE_NAME, std::ios::binary);
    if (!walletFile.is_open())
    {
        std::cout << "error: cannot read wallets file";
    }
    int walletsCount = countWallets(walletFile);
    Wallet *wallets = loadWallets(walletsCount, walletFile);

    for (size_t i = 0; i < walletsCount; i++)
    {
        outputWalletToStdout(wallets[i]);
    }
    free(wallets);
}
double walletBalance(unsigned walletId)
{
    return calculateTotalForWallet(walletId);
}
void walletInfo(unsigned walletId)
{
    std::ifstream walletFile(WALLET_FILE_NAME, std::ios::binary);
    if (!walletFile.is_open())
    {
        std::cout << "error: cannot read wallets file";
    }

    Wallet w;
    while (!walletFile.eof())
    {
        walletFile.read((char *)&w, sizeof(Wallet));
        if (w.id == walletId)
        {
            double coins = walletBalance(walletId);
            std::cout << "Name: " << w.owner << ", money: " << w.fiatMoney << ", FMIcoins: " << coins << std::endl;
            break;
        }
    }

    walletFile.close();
}
