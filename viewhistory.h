#include <string.h>
#include "transaction.h"
#include "customer.h"

// A class representing a customer viewing their transaction history.
class ViewHistory : public Transaction {
public:
    ViewHistory(Customer* customer = nullptr);
    //virtual ~ViewHistory();
    // Prints the customer's transaction history to console
    virtual bool doTransaction() const;
private:
    Customer* customer;
};