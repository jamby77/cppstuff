#include <iostream>
#include <fstream>
#include <string.h>
#include "helpers.h"
#include "transacitons.h"

void writeTransactionToFile(const Transaction &transaction, std::ofstream &ofs)
{
    ofs.write((const char *)&transaction, sizeof(Transaction));
}

void readTransactionFromFile(Transaction &transaction, std::ifstream &ifs)
{
    ifs.read((char *)&transaction, sizeof(Transaction));
}

void outputTransactionToStdout(const Transaction &transaction)
{
    std::cout << "added transaction for ID: " << transaction.receiverId << ", FMICoins amount: " << transaction.fmiCoins << std::endl;
    // std::cout << transaction.time << std::endl;
    // std::cout << transaction.senderId << std::endl;
    // std::cout << transaction.receiverId << std::endl;
}

void storeTransaction(const Transaction &transaction)
{
    std::ofstream trFile(TRANSACTIONS_FILE_NAME, std::ios::binary | std::ios::app);
    if (trFile.is_open())
    {
        writeTransactionToFile(transaction, trFile);
    }
    else
    {
        std::cout << "error : while writing to the wallet data file";
    }

    trFile.close();
}
Transaction addTransaction(unsigned senderId, unsigned receiverId, double fmiCoins)
{
    Transaction t;
    t.time = timeid();
    t.senderId = senderId;
    t.receiverId = receiverId;
    t.fmiCoins = fmiCoins;
    storeTransaction(t);

    return t;
}

void initialTransaction(unsigned walletId, double fiatMoney)
{
    Transaction t = addTransaction(HOLLY_MOTHER_ACCOUNT, walletId, fiatMoney / FMICOIN_RATE);

    outputTransactionToStdout(t);
}

int countTransactions(std ::ifstream &fs)
{
    int length;
    fs.seekg(0, std::ios::end);
    length = fs.tellg();
    fs.seekg(0, std::ios::beg);
    return length / sizeof(Transaction);
}

double calculateTotalForWallet(unsigned wId)
{
    std::ifstream trFile(TRANSACTIONS_FILE_NAME, std::ios::binary);
    if (!trFile.is_open())
    {
        std::cout << "error : while writing to the wallet data file";
        return 0;
    }
    size_t s = sizeof(Transaction);
    Transaction t;
    double total = 0;
    while (trFile.good())
    {
        trFile.read((char *)&t, s);
        if (trFile && t.senderId == wId)
        {
            // if wallet is sender deduct amount from total
            total -= t.fmiCoins;
        }
        else if (trFile && t.receiverId == wId)
        {
            // if wallet is receiver, add amount to total
            total += t.fmiCoins;
        }
    }

    trFile.close();

    return total;
}