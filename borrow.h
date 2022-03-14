/**
 * @file borrow.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a customer borrowing a movie from the store.
 * @date 2022-03-14
 */

#ifndef _BORROW_H
#define _BORROW_H

#include "transaction.h"

class Borrow: public Transaction {
public:

    // Constructor and Destructor
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