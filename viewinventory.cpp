#include "viewinventory.h"

ViewInventory::ViewInventory(MovieList* store) {
    this->store = store;
}

bool ViewInventory::doTransaction() const {
    if (store == nullptr) {
        cout << "Store does not exist." << endl;
        return false;
    } else {
        store->viewInventory();
        cout << endl;
        return true;
    }
}
