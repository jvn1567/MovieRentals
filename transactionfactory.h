/**
 * @file transactionfactory.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Creates different kinds of transaction object based on the input.
 * @date 2022-03-14
 */

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <string.h>
#include <sstream>
#include "customerlist.h"
#include "movielist.h"
#include "transaction.h"

using namespace std;

class TransactionFactory {
public:
    /**------------------------------------------------------------------
     * createTransaction
     * 
     * Processes the transaction command passed in the parameter, creates 
     * and returns the transaction object.
     * Parameter: store is the pointer to the store's MovieList. customers
     * is pointer to the store's customer list. line is the transaction
     * command being processed.
     ------------------------------------------------------------------*/
    Transaction* createTransaction(MovieList* store, CustomerList* customers, string line);
};
#endif