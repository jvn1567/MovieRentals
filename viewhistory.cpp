#include "viewhistory.h"
#include "businesslogic.h"

ViewHistory::ViewHistory(int customerId) {
    this->customerId = customerId;
}

void ViewHistory::doTransaction(map<Movie*, int>* store = nullptr, CustomerNode** customers) const {
    //
}