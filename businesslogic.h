#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include "customerlist.h"
#include "movie.h"

// A class representing a general transaction.
class BusinessLogic {
public:
    BusinessLogic();
    ~BusinessLogic();
    bool buildMovies(string filename);
    bool buildCustomers(string filename);
    bool processTransactions(string filename);
    
private:

    MovieList* store;
    CustomerList* customers;
};

#endif