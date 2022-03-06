#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>
using namespace std;

class Customer {
public:
    Customer(int customerId);
    void addCustomer(int customerId);
    void addTransaction(int customerId, string transaction);
private:
};

#endif