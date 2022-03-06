#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <string.h>
#include <sstream>

using namespace std;

// Reads in raw transaction data to create the correct Transaction type.
class TransactionFactory {
public:
    static Transaction* createTransaction(string command, istringstream& input);
};

#endif