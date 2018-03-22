#include <iostream>
#include <fstream>
#include <string>
#include "./helpers.h"
#include "./transacitons.h"

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
    std::cout << transaction.time << std::endl;
    std::cout << transaction.senderId << std::endl;
    std::cout << transaction.receiverId << std::endl;
}

void storeTransaction(const Transaction &transaction)
{
    std::ofstream trFile(TRANSACTIONS_FILE_NAME, std::ios::binary | std::ios::app);
    if (trFile.is_open())
    {
        writeTransactionToFile(transaction, trFile);
        outputTransactionToStdout(transaction);
        std::cout << "Successfully added !" << std::endl;
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