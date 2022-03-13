#include "return.h"

Return::Return(Movie* movie) {
    this->movie = movie;
}

void Return::doTransaction(map<Movie*, int>* store, CustomerNode** customers) const {
    //
}