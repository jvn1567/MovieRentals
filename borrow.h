#ifndef _BORROW_H
#define _BORROW_H

#include "transaction.h"

class Borrow: public Transaction {
public:
    Borrow(int customerId = 0, Movie* movie = nullptr);
    // Removes a movie from the store and adds it to the customer's inventory.
    virtual void doTransaction(map<Movie*, int>* store, CustomerNode** customers) const;
private:
    int customerId;
    Movie* movie;
    CustomerNode* findCustomer(CustomerNode** customers);
};

#endif