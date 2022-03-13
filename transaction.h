#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h"
#include "movie.h"
#include <map>
using namespace std;

// A class representing a general transaction.
class Transaction {
public:
    Transaction();
    virtual void doTransaction(map<Movie*, int>* store, CustomerNode** customers) const = 0;
    // sets the store inventory to add/remove from
    void setInventory(map<Movie*, int>* newStore);
};

#endif