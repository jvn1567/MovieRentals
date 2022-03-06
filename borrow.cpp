#include "borrow.h"

Borrow::Borrow(Inventory* store = nullptr, Customer** customers = nullptr) {
  this->store = store;
  this->customers = customers;
}

void Borrow::doTransaction(Customer* customer, string movie) const {
  
}