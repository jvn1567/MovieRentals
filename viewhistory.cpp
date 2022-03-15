/**
 * @file viewhistory.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Views the history of a customer's transactions.
 * @date 2022-03-14
 */

#include "viewhistory.h"
#include "businesslogic.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Constructor with with default value of nullptr for the parameter.
 * Parameter: customer is the pointer to the Customer.
 ------------------------------------------------------------------*/
ViewHistory::ViewHistory(Customer* customer) {
    this->customer = customer;
}

/**------------------------------------------------------------------
 * Do Transaction
 * 
 * Prints the customer's rental history to the console. Returns true
 * if the operation was successful.
 ------------------------------------------------------------------*/
bool ViewHistory::doTransaction() const {
    if (customer == nullptr) {
        return false;
    } else {
        cout << "Transaction history for customer " << customer->getID() << ":" << endl;
        cout <<  customer->getHistory() << endl;
        return true;
    }
}