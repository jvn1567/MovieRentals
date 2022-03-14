#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h"
#include "movie.h"
#include <map>
using namespace std;

// A class representing a general transaction.
class Transaction {
public:
    virtual ~Transaction() = 0;
    virtual bool doTransaction() const = 0;
};

#endif