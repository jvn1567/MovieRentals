#ifndef _RETURN_H
#define _RETURN_H

#include <string.h>
#include "transaction.h"
#include "customer.h"

class Return: public Transaction {
public:
    Return();
    // Takes the movie from the customer's inventory and adds it back to the store.
    virtual void doTransaction(Customer* customer, string movie) const;
};

#endif