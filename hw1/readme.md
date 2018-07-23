# FMI Coin

### https://learn.fmi.uni-sofia.bg/mod/assign/view.php?id=99876

### Common

#### Parse command line arguments

1.  Learn how to use command line arguments in C++
    1.  argv[0] is always program m_name and can be safely ignored
    2.  argv[1] is the m_name of the command to execute, after retrieving it, verify it is allowed
    3.  argv[2] and up are values that will vary from command to command and need to be verified
    4.  If there is any error with parsing command line arguments - not enough arguments, wrong arguments, wrong order of arguments etc. a help message must be displayed. The help message can be just fixed text explaining how to use the program.

### add-wallet command

1.  Usage: <pre>> ./fmicoin add-wallet \<amount> \<m_name></pre>
    1.  All arguments are required
    2.  As in all Command Line arguments, all of the data comes in as char[] so amount will have to be converted to double - see atof - http://www.cplusplus.com/reference/cstdlib/atof/
    3.  m_name can potentially have multiple words - Iva Mavrodieva Mavrodieva - they will come as separate arguments from argv[3] and on, all these need to be glued together with ' ' - see https://stackoverflow.com/a/1995070/4376125
    4.  Generate unique wallet id - see example in helpers.cpp::nextId()
        <!-- 5.  Load wallet.dat (if exists) into Wallets[] variable -->
        <!-- 6.  On each command, add parsed data to Wallets[] and then write it to wallet.dat -->
    5.  Create transaction for each new wallet equal to amount / 375 (COIN_RATE)
        1.  sender_id is 4294967295 receiver_id is wallet id
        2.  All transactions are stored in transaction.dat
        3.  Transaction consists of unsigned sender_id, unsigned receiver_id, double fmi_coins, long long time

### make-order command

1.  Usage: <pre>> ./fmicoin make-order \<(SELL|BUY)> \<amount_coins> \<wallet_id></pre>
    1.  All arguments are required
    2.  Must parse amount to double, non negative
    3.  must parse wallet id to 32bit unsigned integer
    4.  Verify wallet id is real
    5.  All orders are stored in orders.dat
    6.  Write a wallet-id.time.txt file containing all transactions from the order
        1.  Include sender/recipient names, coins transferred
        2.  Include total number of transactions resulting from order and total amount in real money
2.  Sell
    1.  Calculate available coins per wallet_id and if less than amount, exit execution with error "No sufficient funds to sell"
        a. available coins are result of all transactions for the wallet from transactions.dat
    2.  Check orders.dat for BUY orders
        a. while there are BUY orders, fulfill them until the SELL amount in current order is greater than 0
        b. If there are NO BUY orders, write current SELL order in orders.dat to be sold when there is new BUY order
        c. If there are no ENOUGH BUY orders to sell entire SELL amount, write the reminder amount from SELL into orders.dat
    3.  For any amount sold against a BUY order, make transaction like:
        a. sender_id=SELL[wallet_id], receiver_id=BUY[wallet_id], fmi_coins=amount, time=now()
3.  Buy
    1.  Buyer has enough money in wallet to cover amount \* 375
    2.  Check orders.dat for SELL orders
        a. while there are SELL orders, fulfill them until the BUY amount in current order is greater than 0
        b. If there are NO SELL orders, write current BUY order in orders.dat to be fulfilled when there is new BUY order
        c. If there are no ENOUGH SELL orders to fulfill entire BUY amount, write the reminder amount from BUY amount into orders.dat
    3.  For any amount purchased, make transaction like:
        a. sender_id=SELL[wallet_id], receiver_id=BUY[wallet_id], fmi_coins=amount, time=now()

### quit command

1.  Usage: <pre>> ./fmicoin quit</pre>
    a. Exit the program with goodbye message

### wallet-info command

1.  Usage: <pre> > ./fmicoin wallet-info \<wallet_id></pre>
    1.  All arguments are required
    2.  Show wallet info:
        a. Name
        b. Amount in money
        c. Amount coins
        a. coins are not stored, any time coins are needed, they have to be calculated from transactions.dat

### attract-investors command

Usage: <pre> > ./fmicoin attract-investors</pre>

Make a report about 10 top most rich in coins users.
The report must display a row of information for each user.
Row must contain:
User m_name, transactions made, first transaction time, last transaction time
