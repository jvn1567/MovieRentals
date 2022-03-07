#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>
#include <vector>
using namespace std;

class Customer {
public:
    Customer(int customerId);
    void addTransaction(int customerId, string transaction);
private:
    int customerId;
    map<Movie*, int> inventory;
    vector<string> history;
};

#endif