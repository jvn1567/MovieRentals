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
 * Constructor that initializes a store's customer list.
 * Postcondition: size is zero, capacity is set to INITIAL_SIZE, and
 * CustomerNode* array is all filled with nullptr.
 ------------------------------------------------------------------*/
CustomerList::CustomerList() {
    size = 0;
    capacity = INITIAL_SIZE;
    newList();
}

/**------------------------------------------------------------------
 * clearList
 * 
 * Deletes all heap allocated memory in a CustomerNode array.
 * Parameter: list is the pointer to the CustomerNode array.
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
 * hash
 * 
 * Calculates and returns the hash index value based on the input 
 * customer ID value that is passed as a parameter. 
 ------------------------------------------------------------------*/
int CustomerList::hash(int ID) const {
    return ID % capacity;
}

/**------------------------------------------------------------------
 * nextPrime
 * 
 * Calculates and returns the next largest prime number from the int
 * value passed in as a parameter. * 
 * Precondition: min is a positive integer.
 ------------------------------------------------------------------*/
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
 * get
 * 
 * Finds the pointer to the Customer based on the customer ID passed
 * in as a parameter. Returns nullptr if the customer ID is not found.
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
 * printAll
 * 
 * Prints a list of all the customer ID's in the store's record.
 ------------------------------------------------------------------*/
void CustomerList::printAll() {
    for(int i = 0; i < capacity; i++) {
        CustomerNode* curr = customers[i];
        while(curr != nullptr) {
            int custId = curr->customer->getID();
            cout << custId << endl;
            curr = curr->next;
        }
    }
}

/**------------------------------------------------------------------
 * add
 * 
 * Adds a Customer to the store's customer list. If customer count
 * exceeds load value, expands the array and rehashes.
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