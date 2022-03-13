#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "movielist.h"

class Customer {
public:
    Customer(int ID);
    int getID() const;
    void insert(Movie* movie);
    bool remove(Movie* movie);
private:
    int ID;
    MovieList bag;
};

#endif