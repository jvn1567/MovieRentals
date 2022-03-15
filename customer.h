/**
 * @file customer.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Defines a customer for a movie rental store.
 * @date 2022-03-14
 */

#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "movielist.h"
#include <vector>

class Customer {
public:
    /**------------------------------------------------------------------
     * Constructor
     * 
     * Constructor initializes the customer with an empty list of Movies.
     * Parameter: ID is the customer ID number.
     ------------------------------------------------------------------*/
    Customer(int ID);

    /**------------------------------------------------------------------
     * getID
     * 
     * Returns the customer's ID number.
     ------------------------------------------------------------------*/
    int getID() const;

    /**------------------------------------------------------------------
     * Insert
     * 
     * Adds a movie into the customer's possession.
     * Parameter: movie is the pointer to the Movie being added.
     ------------------------------------------------------------------*/
    void insert(Movie* movie);

    /**------------------------------------------------------------------
     * Remove
     * 
     * Removes a movie from the customer's possession.
     * Parameter: movie is the pointer to the Movie being removed.
     ------------------------------------------------------------------*/
    bool remove(Movie* movie);

    /**------------------------------------------------------------------
     * Count
     * 
     * Returns the number of a specific movie in possesion by the customer.
     * Parameter: movie is the pointer to the Movie being counted.
     ------------------------------------------------------------------*/
    int count(Movie* movie) const;

    /**------------------------------------------------------------------
     * addTransaction
     * 
     * Adds the record of a customer's transaction to the customer's
     * history.
     * Parameter: info is the transaction records being added.
     ------------------------------------------------------------------*/
    void addTransaction(string info);

    /**------------------------------------------------------------------
     * getHistory
     * 
     * Returns the transaction history of the customer.
     ------------------------------------------------------------------*/
    string getHistory() const;
private:
    int ID;
    MovieList bag;
    vector<string> history;
};

#endif