#include <string.h>
#include "transaction.h"
#include "customer.h"

// A class representing a customer viewing their transaction history.
class ViewHistory : public Transaction {
public:
    ViewHistory(int customerId);
    // Prints the customer's transaction history to console
    virtual void doTransaction(map<Movie*, int>* store, CustomerNode** customers) const;
private:
    int customerId;
};