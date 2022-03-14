#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <string.h>
#include <sstream>
#include "customerlist.h"
#include "movielist.h"
#include "transaction.h"

using namespace std;

// Reads in raw transaction data to create the correct Transaction type.
class TransactionFactory {
public:
    Transaction* createTransaction(MovieList* store, CustomerList* customers, string line);
private:
    Movie* getMovie(MovieList* store, string movieType, istringstream& iss);
};
#endif