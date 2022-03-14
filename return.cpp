#include "return.h"

Return::Return(MovieList* store, Customer* customer, Movie* movie) {
    this->store = store;
    this->customer = customer;
    this->movie = movie;
}
/*
Return::~Return() {
    //delete movie;
}
*/

bool Return::doTransaction() const {
    bool success = false;
    if (customer == nullptr) {
        cout << "Invalid customer." << endl;
        return false;
    }

    success = customer->remove(movie);
    if (!success) {
        cout << "Movie was not borrowed." << endl;
    } else {
        store->insert(movie);
        success = true;
    }
    return success;
}