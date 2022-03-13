#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "movielist.h"
#include <vector>

class Customer {
public:
    Customer(int ID);
    int getID() const;
    void insert(Movie* movie);
    bool remove(Movie* movie);
    void addTransaction(string info);
    string getHistory() const;
private:
    int ID;
    MovieList bag;
    vector<string> history;
};

#endif