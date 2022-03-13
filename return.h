#ifndef _RETURN_H
#define _RETURN_H

#include <string.h>
#include "transaction.h"
#include "customer.h"

class Return: public Transaction {
public:
    Return(Movie* movie);
    // Takes the movie from the customer's inventory and adds it back to the store.
    virtual void doTransaction(map<Movie*, int>* store, CustomerNode** customers) const;
private:
    Movie* movie;
};

#endif