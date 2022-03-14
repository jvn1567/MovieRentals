#include "customerlist.h"

void CustomerList::newList() {
    customers = new CustomerNode*[capacity];
    for (int i = 0; i < capacity; i++) {
        customers[i] = nullptr;
    }
}

CustomerList::CustomerList() {
    size = 0;
    capacity = INITIAL_SIZE;
    newList();
}

void CustomerList::clearList(CustomerNode** list) {
    for (int i = 0; i < capacity; i++) {
        while (list[i] != nullptr) {
            CustomerNode* temp = list[i];
            list[i] = list[i]->next;
            delete temp->customer;
            delete temp;
        }
    }
    delete list;
}

CustomerList::~CustomerList() {
    clearList(customers);
}

int CustomerList::hash(int ID) const {
    return ID % capacity;
}

// must be positive integer
int CustomerList::nextPrime(int min) const {
    // ensure odd
    if (min % 2 == 0) {
        return nextPrime(min + 1);
    }
    // check for any factors, or check next odd
    for (int i = 3; i * i <= min; i++) {
        if (min % i == 0) {
            return nextPrime(min + 2);
        }
    }
    return min;
}

void CustomerList::rehash() {
    int oldCapacity = capacity;
    capacity = nextPrime(capacity * 2 + 1);
    CustomerNode** oldList = customers;
    newList();
    for(int i = 0; i < oldCapacity; i++) {
        CustomerNode* curr = oldList[i];
        while (curr != nullptr) {
            add(oldList[i]->customer);
            curr = curr->next;
        }
    }
    clearList(oldList);
}

Customer* CustomerList::get(int ID) {
    int index = hash(ID);
    CustomerNode* curr = customers[index];
    while(curr != nullptr) {
        if (curr->customer->getID() == ID) {
            return curr->customer;
        }
        curr = curr->next;
    }
    return nullptr;
}

void CustomerList::printAll() {
    for(int i = 0; i < capacity; i++) {
        CustomerNode* curr = customers[i];
        while(curr != nullptr) {
            int custId = curr->customer->getID();
            cout << custId << endl;
            curr = curr->next;
        }
    }
}

void CustomerList::add(Customer* customer) {
    try {
        if (customer == nullptr) {
            throw invalid_argument("INVALID CUSTOMER");
        }
    }
    catch (invalid_argument& s) {
        cout << s.what() << endl;
    }
    int index = hash(customer->getID());
    customers[index] = new CustomerNode{customer, customers[index]};
    size++;
    if (size > LOAD_FACTOR * capacity) {
        rehash();
    }
}