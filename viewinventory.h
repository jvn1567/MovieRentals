#include <string.h>
#include "transaction.h"
#include "customer.h"
#include "businesslogic.h"

// A class representing a customer checking the store stock of movies.
class ViewInventory : public Transaction {
public:
    ViewInventory(map<Movie*, int>* store = nullptr);
    // Prints the store's inventory to console.
    virtual void doTransaction(map<Movie*, int>* store, CustomerNode** customers = nullptr) const;
private:
    map<Movie*, int>* store;
};