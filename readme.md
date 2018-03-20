# FMI Coin

### Common

#### Parse command line arguments

1.  Learn how to use command line arguments in C++
    1.  argv[0] is always program name and can be safely ignored
    2.  argv[1] is the name of the command to execute, after retreiving it, verify it is allowed
    3.  argv[2] and up are values that will vary from command to command and need to be verified
    4.  If there is any error with parsing command line arguments - not enough arguments, wrong arguments, wrong order of arguments etc. a help message must be displayed. The help message can be just fixed text explaining how to use the program.

### add-wallet command

1.  Usage: > ./cmd add-wallet <amount> <name>
    1.  All arguments are required
    2.  As in all Command Line arguments, all of the data comes in as char[] so amount will have to be converted to double - see atof - http://www.cplusplus.com/reference/cstdlib/atof/
    3.  name can potentially have multiple words - Iva Mavrodieva Mavrodieva - they will come as separate arguments from argv[3] and on, all these need to be glued together with ' ' - see https://stackoverflow.com/a/1995070/4376125
    4.  Generate unique wallet id - see example in messenger
    5.  Load wallet.dat (if exists) into Wallet[] variable
    6.  On each command, add parsed data to Wallet[] and then write it to wallet.dat
    7.  Create transaction for each new wallet equal to amount / 375 (COIN_RATE)

### make-order command

### quit command

### wallet-info command

### attract-investors command
