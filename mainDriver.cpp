#include "businesslogic.h"
//#include "transaction.h"

int main() {
    BusinessLogic store;

    store.buildMovies("data4movies.txt");
    store.buildCustomers("data4customers.txt");
    store.processTransactions("data4commands.txt");
    return 0;
}