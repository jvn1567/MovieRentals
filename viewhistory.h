#include <string.h>
#include "transaction.h"
#include "customer.h"

// A class representing a customer viewing their transaction history.
class ViewHistory : public Transaction {
public:
    ViewHistory();
    // Prints the customer's transaction history to console
    virtual void doTransaction(Customer* customer, string movie = "") const;
};