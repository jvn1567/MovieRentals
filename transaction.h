#ifndef TRANSACTION_H
#define TRANSACTION_H

using namespace std;

// A class representing a general transaction.
class Transaction {
public:
    Transaction();
    virtual void doTransaction(Inventory* customer, string movie) const = 0;
    // sets the store inventory to add/remove from
    static void setInventory(Inventory* store);
private:
    static Inventory* store;
    static Customer* cust;
};

#endif