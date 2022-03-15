/**
 * @file borrow.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Defines a customer returning a movie to the store.
 * @date 2022-03-14
 */

#ifndef _RETURN_H
#define _RETURN_H

#include <string.h>
#include "transaction.h"
#include "customer.h"
#include "businesslogic.h"

class Return: public Transaction {
public:
    /**------------------------------------------------------------------
     * Constructor
     * 
     * Constructor with with default values of nullptr for each parameter.
     * Parameter: store is the pointer to the store's MovieList. customer
     * is pointer to the Customer. movie is the pointer to the Movie being
     * returned.
     ------------------------------------------------------------------*/
    Return(MovieList* store = nullptr, Customer* customer = nullptr, Movie* movie = nullptr);

    /**------------------------------------------------------------------
     * Destructor
     * 
     * Clears heap-allocated memory.
     ------------------------------------------------------------------*/
    ~Return();

    /**------------------------------------------------------------------
     * Do Transaction
     * 
     * Returns a movie from the customer and adds it to the store's
     * inventory.
     * Returns true if the transaction was successful.
     ------------------------------------------------------------------*/
    virtual bool doTransaction() const;
private:
    MovieList* store; //pointer to the store's MovieList
    Customer* customer; //pointer to the Customer
    Movie* movie; //pointer to the Movie
};

#endif