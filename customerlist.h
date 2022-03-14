// TODO: real header
// Open-hashed list of customers

#ifndef _CUSTOMERLIST_H
#define _CUSTOMERLIST_H

#include "customer.h"

class CustomerList {
public:
    // Constructor / Destructor
    CustomerList();
    ~CustomerList();

    // Accessors
    Customer* get(int ID);
    void printAll();

    // Add
    void add(Customer* customer);
    

private:

    // node for open hashing
    typedef struct CustomerNode {
        Customer* customer;
        CustomerNode* next;
    } CustomerNode;

    // Constants
    static const int INITIAL_SIZE  = 31;
    static constexpr double LOAD_FACTOR  = 0.4;

    // Members
    int size;
    int capacity;
    CustomerNode** customers;

    // Internal functions
    int hash(int ID) const;
    int nextPrime(int min) const;
    void rehash();

    // Helpers
    void newList();
    void clearList(CustomerNode** list);
};

#endif