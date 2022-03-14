#include "return.h"

Return::Return(MovieList* store, Customer* customer, Movie* movie) {
    this->store = store;
    this->customer = customer;
    this->movie = movie;
}

Return::~Return() {
    delete movie;
}

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
        cout << "Movie was not borrowed." << endl;
    }
    return false;
}