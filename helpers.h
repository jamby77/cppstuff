#include <stdio.h>
#include <time.h>

const char *const addWalletCommand = "add-wallet";
const char *const makeOrderCommand = "make-order";
const char *const quitCommand = "quit";
const char *const walletInfoCommand = "wallet-info";
const char *const attractInvestorsCommand = "attract-investors";

void printUsage();

unsigned int timeid();
int nextId();