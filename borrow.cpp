#include "borrow.h"
#include "businesslogic.h"
#include "movielist.h"

Borrow::Borrow(MovieList* store, Customer* customer, Movie* movie) {
    this->store = store,
    this->customer = customer;
    this->movie = movie;
}

/*
Borrow::~Borrow() {
    //delete movie;
}
*/

bool Borrow::doTransaction() const {
    bool success = false;
    if (customer == nullptr) {
        cout << "Invalid customer." << endl;
        return false;
    }
    if (movie == nullptr) {
        cout << "Borrow: movie is nullptr" << endl;
    }
    success = store->remove(movie);
    if (!success) {
        cout << "Movie is out of stock." << endl;
    } else {
        customer->insert(movie);
    }
    return success;
}