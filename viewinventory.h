#include <string.h>
#include "transaction.h"
#include "customer.h"
#include "businesslogic.h"

// A class representing a customer checking the store stock of movies.
class ViewInventory : public Transaction {
public:
    ViewInventory(MovieList* store = nullptr);
    //virtual ~ViewInventory();
    // Prints the store's inventory to console.
    virtual bool doTransaction() const;
private:
    MovieList* store;
};