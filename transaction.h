/**
 * @file transaction.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Defines a movie transaction. A pure virtual class.
 * @date 2022-03-14
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h"
#include "movie.h"
#include <map>
using namespace std;

// A class representing a general transaction.
class Transaction {
public:
    /**------------------------------------------------------------------
     * Destructor
     * 
     * Clears heap-allocated memory. Pure virtual method.
     ------------------------------------------------------------------*/
    virtual ~Transaction() = 0;

    /**------------------------------------------------------------------
     * Do Transaction
     * 
     * Performs a transction for the movie store. Pure virtual method.
     ------------------------------------------------------------------*/
    virtual bool doTransaction() const = 0;
};

#endif