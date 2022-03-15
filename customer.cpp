/**
 * @file customer.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Defines a customer for a movie rental store.
 * @date 2022-03-14
 */

#include "customer.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Constructor initializes the customer with an empty list of Movies.
 * Parameter: ID is the customer ID number.
 ------------------------------------------------------------------*/
Customer::Customer(int ID) : ID(ID) {
    bag = MovieList();
}

/**------------------------------------------------------------------
 * getID
 * 
 * Returns the customer's ID number.
 ------------------------------------------------------------------*/
int Customer::getID() const {
    return ID;
}

/**------------------------------------------------------------------
 * Insert
 * 
 * Adds a movie into the customer's possession.
 * Parameter: movie is the pointer to the Movie being added.
 ------------------------------------------------------------------*/
void Customer::insert(Movie* movie) {
    bag.insert(movie);
}

/**------------------------------------------------------------------
 * Remove
 * 
 * Removes a movie from the customer's possession.
 * Parameter: movie is the pointer to the Movie being removed.
 ------------------------------------------------------------------*/
bool Customer::remove(Movie* movie) {
    return bag.remove(movie);
}

/**------------------------------------------------------------------
 * Count
 * 
 * Returns the number of a specific movie in possesion by the customer.
 * Parameter: movie is the pointer to the Movie being counted.
 ------------------------------------------------------------------*/
int Customer::count(Movie* movie) const {
    return bag.count(movie);
}

/**------------------------------------------------------------------
 * addTransaction
 * 
 * Adds the record of a customer's transaction to the customer's
 * history.
 * Parameter: info is the transaction records being added.
 ------------------------------------------------------------------*/
void Customer::addTransaction(string info) {
    history.push_back(info);
}

/**------------------------------------------------------------------
 * getHistory
 * 
 * Returns the transaction history of the customer.
 ------------------------------------------------------------------*/
string Customer::getHistory() const {
    string hist;
    for (string line : history) {
        hist += line;
        hist += "\n";
    }
    if (history.size() == 0) {
        hist += "No transactions have been performed.\n";
    }
    return hist;
}