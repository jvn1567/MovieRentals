/**
 * @file borrow.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a customer borrowing a movie from the store.
 * @date 2022-03-14
 */

#include "borrow.h"
#include "businesslogic.h"
#include "movielist.h"
#include "classic.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Creates a Borrow transaction object, with default values of
 * nullptr for each pointer.
 ------------------------------------------------------------------*/
Borrow::Borrow(MovieList* store, Customer* customer, Movie* movie) {
    this->store = store,
    this->customer = customer;
    this->movie = movie;
}

/**------------------------------------------------------------------
 * Destructor
 * 
 * Clears heap-allocated memory.
 ------------------------------------------------------------------*/
Borrow::~Borrow() {}

/**------------------------------------------------------------------
 * Do Transaction
 * 
 * Removes a movie from the store and adds it to the customer's
 * inventory. The store is assumed to be valid.
 * Returns true if the transaction was successful.
 ------------------------------------------------------------------*/
bool Borrow::doTransaction() const {
    bool success = false;
    bool inStock = false;
    if (customer == nullptr) {
        cout << "Invalid customer." << endl;
	    delete movie;
    } else if (movie == nullptr) {
        cout << "Invalid movie information." << endl;
    } else {
        inStock = store->remove(movie);
        // check for same classic of different actor
        Movie* temp = nullptr;
        if (!inStock && movie->getType() == 'C') {
            Movie* fullMovie = store->findMovie(movie);
            if (fullMovie != nullptr) {
                temp = ((Classic*)fullMovie)->actorlessCopy();
                inStock = store->remove(temp);
            }
        }
        // update customer if in stock
        if (inStock) {
            bool alreadyInTree = customer->count(movie) > -1;
            customer->insert(movie);
            success = true;
            string tag = "Borrowed: ";
            tag += (temp == nullptr ? movie->toStringShort() : temp->toStringShort());
            customer->addTransaction(tag);
            if (alreadyInTree) {
                delete movie;
            }
        } else {
            cout << "Movie is out of stock." << endl;
            cout << movie->toStringShort() << endl;    // DEBUG 
	        delete movie;
        }
        if (temp != nullptr) {
            delete temp;
        }
    }
    return success;
}