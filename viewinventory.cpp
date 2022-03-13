#include "viewinventory.h"

ViewInventory::ViewInventory(map<Movie*, int>* store) {
    this->store = store;
}

void ViewInventory::doTransaction(map<Movie*, int>* store, CustomerNode** customers = nullptr) const {
    //
}
