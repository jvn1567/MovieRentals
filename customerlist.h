/**
 * @file customerlist.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a list of customers, stored in a hash table.
 * @date 2022-03-14
 */

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

    // Add
    void add(Customer* customer);

private:

    // Node for open hashing
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