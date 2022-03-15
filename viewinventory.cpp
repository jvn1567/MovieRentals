/**
 * @file viewinventory.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Views the store's current inventory of movies.
 * @date 2022-03-14
 */

#include "viewinventory.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Constructor with with default values of nullptr for the parameter.
 * Parameter: store is the pointer to the store's MovieList.
 ------------------------------------------------------------------*/
ViewInventory::ViewInventory(MovieList* store) {
    this->store = store;
}

/**------------------------------------------------------------------
 * Do Transaction
 * 
 * Prints the customer's rental history to the console.
 * Returns true if operation was successful.
 ------------------------------------------------------------------*/
bool ViewInventory::doTransaction() const {
    if (store == nullptr) {
        cout << "Store does not exist." << endl;
        return false;
    } else {
        store->viewInventory();
        cout << endl;
        return true;
    }
}
