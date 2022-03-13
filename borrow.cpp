#include "borrow.h"
#include "businesslogic.h"

Borrow::Borrow(int customerId, Movie* movie) {
  this->customerId = customerId;
  this->movie = movie;
}

CustomerNode* Borrow::findCustomer(CustomerNode** customers) {
  for (int i = 0; i < 101; i++) {
    CustomerNode* curr = customers[i];

  }
}

void Borrow::doTransaction(map<Movie*, int>* store, CustomerNode** customers) const {
    if (movie == nullptr) {
      cout << "Movie not found" << endl;
    } else if ((*store)[movie] > 0) {
        (*store)[movie] -= 1;

    } else {
      cout << "Movie is out of stock" << endl;
    }
}