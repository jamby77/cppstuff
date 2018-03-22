#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

#define TRANSACTIONS_FILE_NAME "transactions.dat"

struct Transaction
{
    long long time;
    unsigned senderId;
    unsigned receiverId;
    double fmiCoins;
};

const long HOLLY_MOTHER_ACCOUNT = 4294967295;
const unsigned short FMICOIN_RATE = 375;

void initialTransaction(unsigned walletId, double fiatMoney);
Transaction addTransaction(unsigned senderId, unsigned receiverId, double fmiCoins);
double calculateTotalForWallet(unsigned wId);

#endif // !__TRANSACTION_H__
