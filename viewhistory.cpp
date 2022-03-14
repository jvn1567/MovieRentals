#include "viewhistory.h"
#include "businesslogic.h"

ViewHistory::ViewHistory(Customer* customer) {
    this->customer = customer;
}

bool ViewHistory::doTransaction() const {
    if (customer == nullptr) {
        return false;
    } else {
        string history = customer->getHistory();
        cout << "Customer transaction history:" << endl;
        cout <<  history << endl;
        return true;
    }
}