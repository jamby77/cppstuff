#include <string>
#define WALLET_FILE_NAME "wallets.dat"
const size_t MAXN = 256;

struct Wallet
{
    char owner[MAXN];
    unsigned id;
    double fiatMoney;
};

unsigned addWallet(int argc, char *argv[]);
void listWallets();
Wallet *loadWallets(int wc, std::ifstream &fs);