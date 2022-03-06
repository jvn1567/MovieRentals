#include <string.h>
#include "transaction.h"
#include "customer.h"

class Borrow: public Transaction {
public:
  Borrow();
  // Removes a movie from the store and adds it to the customer's inventory.
  virtual void doTransaction(Customer* customer, string movie) const;
}