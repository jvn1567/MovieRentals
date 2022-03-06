#include <string.h>
#include <sstream>


#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

using namespace std;

// Reads in raw transaction data to create the correct Transaction type.
class TransactionFactory {
public:
    static Transaction* createTransaction(string command, istringstream& input);
};

#endif