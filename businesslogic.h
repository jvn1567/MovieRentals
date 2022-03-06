#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include <map>
#include "customer.h"
#include "movie.h"

// A class representing a general transaction.
class BusinessLogic {
public:
    BusinessLogic();
    bool buildMovies(string filename);
    bool buildCustomers(string filename);
    bool processTransactions(string filename);
private:
    map<Movie*, int>* store;
    static Customer** customers;
};

#endif