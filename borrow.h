#ifndef _BORROW_H
#define _BORROW_H

#include "transaction.h"

class Borrow: public Transaction {
public:
    Borrow();
    // Removes a movie from the store and adds it to the customer's inventory.
    virtual void doTransaction(Customer* customer, string movie) const;
};

#endif