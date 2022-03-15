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
    /**------------------------------------------------------------------
     * Constructor
     * 
     * Constructor with with default values of nullptr for each parameter.
     * Parameter: store is the pointer to the store's MovieList. customer
     * is pointer to the Customer. movie is the pointer to the Movie being
     * borrowed.
     ------------------------------------------------------------------*/
    Borrow(MovieList* store = nullptr, Customer* customer = nullptr, Movie* movie = nullptr);
    
    /**------------------------------------------------------------------
     * Do Transaction
     * 
     * Removes a movie from the store and adds it to the customer's
     * inventory.
     * Returns true if the transaction was successful.
     ------------------------------------------------------------------*/
    virtual bool doTransaction() const;
private:
    MovieList* store; //pointer to the store's MovieList
    Customer* customer; //pointer to the customer
    Movie* movie; //pointer to the movie
};

#endif