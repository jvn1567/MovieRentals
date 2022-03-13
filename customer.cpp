#include "customer.h"

Customer::Customer(int ID) : ID(ID) {
    bag = MovieList();
}

int Customer::getID() const {
    return ID;
}

void Customer::insert(Movie* movie) {
    bag.insert(movie);
}

bool Customer::remove(Movie* movie) {
    bag.remove(movie);
}