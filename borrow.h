#ifndef _BORROW_H
#define _BORROW_H

#include "transaction.h"

class Borrow: public Transaction {
public:
    Borrow(MovieList* store = nullptr, Customer* customer = nullptr, Movie* movie = nullptr);
    ~Borrow();
    // Removes a movie from the store and adds it to the customer's inventory.
    virtual bool doTransaction() const;
private:
    MovieList* store;
    Customer* customer;
    Movie* movie;
};

#endif