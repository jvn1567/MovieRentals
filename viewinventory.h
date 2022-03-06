#include <string.h>
#include "transaction.h"
#include "customer.h"

// A class representing a customer checking the store stock of movies.
class ViewInventory : public Transaction {
public:
    ViewInventory();
    // Prints the store's inventory to console.
    virtual void doTransaction(CustomerInventory* store = nullptr, string movie = "") const;
};