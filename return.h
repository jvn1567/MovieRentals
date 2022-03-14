#ifndef _RETURN_H
#define _RETURN_H

#include <string.h>
#include "transaction.h"
#include "customer.h"
#include "businesslogic.h"


class Return: public Transaction {
public:
    Return(MovieList* store = nullptr, Customer* customer = nullptr, Movie* movie = nullptr);
    //~Return();
    // Takes the movie from the customer's inventory and adds it back to the store.
    virtual bool doTransaction() const;
private:
    MovieList* store;
    Customer* customer;
    Movie* movie;
};

#endif