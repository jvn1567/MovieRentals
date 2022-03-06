//#include "inventory.h"
#include "customer.h"
#include "movie.h"

#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

using namespace std;

struct movieNode {
    Movie movie();
    int count;
    movieNode* left;
    movieNode* right;
};

// A class representing a general transaction.
class BusinessLogic {
public:
    BusinessLogic();
    bool buildMovies(string filename);
    bool buildCustomers(string filename);
    bool processTransactions(string filename);
private:
    movieNode* root;
    static Customer** customers;
};

#endif