/**
 * @file viewinventory.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Views the store's current inventory of movies.
 * @date 2022-03-14
 */

#include <string.h>
#include "transaction.h"
#include "customer.h"
#include "businesslogic.h"

class ViewInventory : public Transaction {
public:
    /**------------------------------------------------------------------
     * Constructor
     * 
     * Constructor with with default values of nullptr for the parameter.
     * Parameter: store is the pointer to the store's MovieList.
     ------------------------------------------------------------------*/
    ViewInventory(MovieList* store = nullptr);
    
    /**------------------------------------------------------------------
     * Do Transaction
     * 
     * Prints the customer's rental history to the console.
     * Returns true if operation was successful.
     ------------------------------------------------------------------*/
    virtual bool doTransaction() const;
private:
    MovieList* store;
};