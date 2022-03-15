/**
 * @file viewhistory.ch
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Views the history of a customer's transactions.
 * @date 2022-03-14
 */

#include <string.h>
#include "transaction.h"
#include "customer.h"

// A class representing a customer viewing their transaction history.
class ViewHistory : public Transaction {
public:
    /**------------------------------------------------------------------
     * Constructor
     * 
     * Constructor with with default value of nullptr for the parameter.
     * Parameter: customer is the pointer to the Customer.
     ------------------------------------------------------------------*/
    ViewHistory(Customer* customer = nullptr);

    /**------------------------------------------------------------------
     * Do Transaction
     * 
     * Prints the customer's rental history to the console. Returns true
     * if the operation was successful.
     ------------------------------------------------------------------*/
    virtual bool doTransaction() const;
private:
    Customer* customer;
};