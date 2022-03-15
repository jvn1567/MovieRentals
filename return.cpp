/**
 * @file borrow.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Defines a customer returning a movie to the store.
 * @date 2022-03-14
 */

#include "return.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Constructor with with default values of nullptr for each parameter.
 * Parameter: store is the pointer to the store's MovieList. customer
 * is pointer to the Customer. movie is the pointer to the Movie being
 * returned.
 ------------------------------------------------------------------*/
Return::Return(MovieList* store, Customer* customer, Movie* movie) {
    this->store = store;
    this->customer = customer;
    this->movie = movie;
}

/**------------------------------------------------------------------
 * Destructor
 * 
 * Clears heap-allocated memory.
 ------------------------------------------------------------------*/
Return::~Return() {
    delete movie;
}

/**------------------------------------------------------------------
 * Do Transaction
 * 
 * Returns a movie from the customer and adds it to the store's
 * inventory.
 * Returns true if the transaction was successful.
 ------------------------------------------------------------------*/
bool Return::doTransaction() const {
    if (customer == nullptr) {
        cout << "Invalid customer." << endl;
    } else if (movie == nullptr) {
        cout << "Invalid movie information." << endl;
    } else if (customer->remove(movie)) {
        store->insert(movie);
        customer->addTransaction("Returned: " + movie->toStringShort());
        return true;
    } else {
        cout << "Movie was not borrowed by customer." << endl;
    }
    return false;
}