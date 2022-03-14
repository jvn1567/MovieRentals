/**
 * @file customerlist.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a list of customers, stored in a hash table.
 * @date 2022-03-14
 */

#include "customerlist.h"

/**------------------------------------------------------------------
 * New List
 * 
 * Initializes the hash array with nullptr default values.
 ------------------------------------------------------------------*/
void CustomerList::newList() {
    customers = new CustomerNode*[capacity];
    for (int i = 0; i < capacity; i++) {
        customers[i] = nullptr;
    }
}

/**------------------------------------------------------------------
 * Constructor
 * 
 * Creates an empty list with an intial prime-number sized array.
 ------------------------------------------------------------------*/
CustomerList::CustomerList() {
    size = 0;
    capacity = INITIAL_SIZE;
    newList();
}

/**------------------------------------------------------------------
 * Clear List
 * 
 * Clears all heap-allocated memory in the passed in array of nodes.
 ------------------------------------------------------------------*/
void CustomerList::clearList(CustomerNode** list) {
    for (int i = 0; i < capacity; i++) {
        while (list[i] != nullptr) {
            CustomerNode* temp = list[i];
            list[i] = list[i]->next;
            delete temp->customer;
            delete temp;
        }
    }
    delete list;
}

/**------------------------------------------------------------------
 * Destructor
 * 
 * Clears heap-allocated memory.
 ------------------------------------------------------------------*/
CustomerList::~CustomerList() {
    clearList(customers);
}

/**------------------------------------------------------------------
 * Hash
 * 
 * Returns a hash value generated from passed-in customer ID number.
 ------------------------------------------------------------------*/
int CustomerList::hash(int ID) const {
    return ID % capacity;
}

/**------------------------------------------------------------------
 * Next Prime
 * 
 * Finds a prime number greater or equal to the specified value.
 ------------------------------------------------------------------*/
// must be positive integer
int CustomerList::nextPrime(int min) const {
    // ensure odd
    if (min % 2 == 0) {
        return nextPrime(min + 1);
    }
    // check for any factors, or check next odd
    for (int i = 3; i * i <= min; i += 2) {
        if (min % i == 0) {
            return nextPrime(min + 2);
        }
    }
    return min;
}

/**------------------------------------------------------------------
 * Rehash
 * 
 * Expands the array to at least double its size and rehashes items.
 ------------------------------------------------------------------*/
void CustomerList::rehash() {
    int oldCapacity = capacity;
    capacity = nextPrime(capacity * 2 + 1);
    CustomerNode** oldList = customers;
    newList();
    for(int i = 0; i < oldCapacity; i++) {
        CustomerNode* curr = oldList[i];
        while (curr != nullptr) {
            add(oldList[i]->customer);
            curr = curr->next;
        }
    }
    clearList(oldList);
}

/**------------------------------------------------------------------
 * Get
 * 
 * Takes an integer ID number and returns the corresponding Customer
 * pointer, or nullptr if the corresponding customer does not exist.
 ------------------------------------------------------------------*/
Customer* CustomerList::get(int ID) {
    int index = hash(ID);
    CustomerNode* curr = customers[index];
    while(curr != nullptr) {
        if (curr->customer->getID() == ID) {
            return curr->customer;
        }
        curr = curr->next;
    }
    return nullptr;
}

/**------------------------------------------------------------------
 * Add
 * 
 * Adds the Customer pointer to the CustomerList. If the load factor
 * is reached, the array is expanded and rehashed.
 ------------------------------------------------------------------*/
void CustomerList::add(Customer* customer) {
    if (customer == nullptr) {
        throw invalid_argument("INVALID CUSTOMER");
    }
    int index = hash(customer->getID());
    customers[index] = new CustomerNode{customer, customers[index]};
    size++;
    if (size > LOAD_FACTOR * capacity) {
        rehash();
    }
}