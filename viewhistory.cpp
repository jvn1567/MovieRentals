#include "viewhistory.h"
#include "businesslogic.h"

ViewHistory::ViewHistory(Customer* customer) {
    this->customer = customer;
}

bool ViewHistory::doTransaction() const {
    if (customer == nullptr) {
        return false;
    } else {
        customer->getHistory();
        return true;
    }
}