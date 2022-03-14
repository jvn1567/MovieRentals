#include "borrow.h"
#include "businesslogic.h"
#include "movielist.h"
#include "classic.h"

Borrow::Borrow(MovieList* store, Customer* customer, Movie* movie) {
    this->store = store,
    this->customer = customer;
    this->movie = movie;
}

Borrow::~Borrow() {}

// store assumed to always be valid
bool Borrow::doTransaction() const {
    bool success = false;
    bool inStock = false;
    if (customer == nullptr) {
        cout << "Invalid customer." << endl;
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
            customer->insert(movie);
            success = true;
            string tag = "Borrowed: ";
            tag += (temp == nullptr ? movie->toStringShort() : temp->toStringShort());
            customer->addTransaction(tag);
        } else { 
            cout << "Movie is out of stock." << endl;
            cout << movie->toStringShort() << endl;    // DEBUG 
        }
        if (temp != nullptr) {
            delete temp;
        }
    }
    return success;
}