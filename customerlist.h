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
    /**------------------------------------------------------------------
     * Constructor
     * 
     * Constructor that initializes a store's customer list.
     * Postcondition: size is zero, capacity is set to INITIAL_SIZE, and
     * CustomerNode* array is all filled with nullptr.
     ------------------------------------------------------------------*/
    CustomerList();

    /**------------------------------------------------------------------
     * Destructor
     * 
     * Clears heap-allocated memory.
     ------------------------------------------------------------------*/
    ~CustomerList();

    // Accessors
    /**------------------------------------------------------------------
     * get
     * 
     * Finds the pointer to the Customer based on the customer ID passed
     * in as a parameter. Returns nullptr if the customer ID is not found.
     ------------------------------------------------------------------*/
    Customer* get(int ID);

    /**------------------------------------------------------------------
     * printAll
     * 
     * Prints a list of all the customer ID's in the store's record.
     ------------------------------------------------------------------*/
    void printAll();

    /**------------------------------------------------------------------
     * add
     * 
     * Adds a Customer to the store's customer list.
     ------------------------------------------------------------------*/
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
    int size; //current number of customers
    int capacity; //capacity size of the customer list array.
    CustomerNode** customers;

    // Internal functions
    /**------------------------------------------------------------------
     * hash
     * 
     * Calculates and returns the hash index value based on the input 
     * customer ID value that is passed as a parameter. 
     ------------------------------------------------------------------*/
    int hash(int ID) const;

    /**------------------------------------------------------------------
     * nextPrime
     * 
     * Calculates and returns the next largest prime number from the int
     * value passed in as a parameter. * 
     * Precondition: min is a positive integer.
     ------------------------------------------------------------------*/
    int nextPrime(int min) const;

    /**------------------------------------------------------------------
     * rehash
     * 
     * Roughly doubles the size of the customer list capacity.
     ------------------------------------------------------------------*/
    void rehash();

    // Helpers
    /**------------------------------------------------------------------
     * newList
     * 
     * Constructor that creates a new CustomerNode* array and fills it
     * with nullptr.
     ------------------------------------------------------------------*/
    void newList();

    /**------------------------------------------------------------------
     * clearList
     * 
     * Deletes all heap allocated memory in a CustomerNode array.
     * Parameter: list is the pointer to the CustomerNode array.
     ------------------------------------------------------------------*/
    void clearList(CustomerNode** list);

};

#endif