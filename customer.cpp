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
    return bag.remove(movie);
}

int Customer::count(Movie* movie) const {
    return bag.count(movie);
}

void Customer::addTransaction(string info) {
    history.push_back(info);
}

string Customer::getHistory() const {
    string hist;
    for (string line : history) {
        hist += line;
        hist += "\n";
    }
    if (history.size() == 0) {
        hist += "No transctions have been performed.\n";
    }
    return hist;
}