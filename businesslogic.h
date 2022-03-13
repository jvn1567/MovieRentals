#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <map>
#include "customer.h"
#include "movie.h"

struct CustomerNode {
    Customer* customer;
    CustomerNode* next;
    CustomerNode(Customer* customer = nullptr, CustomerNode* next = nullptr);
};

// A class representing a general transaction.
class BusinessLogic {
public:
    BusinessLogic();
    ~BusinessLogic();
    bool buildMovies(string filename);
    bool buildCustomers(string filename);
    bool processTransactions(string filename);
    
private:
    map<Movie*, int>* store;
    static CustomerNode** customers;

    int arraySize;
    void addCustomer(int customerId);
    int hash(int customerId) const;
    int rehash();
    Customer* getCustomer(int customerId);
};

#endif