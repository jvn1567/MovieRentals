#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <string.h>
#include <sstream>

using namespace std;

// Reads in raw transaction data to create the correct Transaction type.
class TransactionFactory {
public:
    TransactionFactory();
    Transaction* createTransaction(map<Movie*, int>* store, string line);
private:
    Movie* getMovie(map<Movie*, int>* store, string movieType, istringstream& iss);
};

#endif