/**
 * @file transactionfactory.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Creates different kinds of transaction object based on the input.
 * @date 2022-03-14
 */

#include "transaction.h"
#include "transactionfactory.h"
#include "moviefactory.h"
#include "movielist.h"
#include "borrow.h"
#include "return.h"
#include "viewhistory.h"
#include "viewinventory.h"
#include "businesslogic.h"

/**------------------------------------------------------------------
 * createTransaction
 * 
 * Processes the transaction command passed in the parameter, creates 
 * and returns the transaction object.
 * Parameter: store is the pointer to the store's MovieList. customers
 * is pointer to the store's customer list. line is the transaction
 * command being processed.
 ------------------------------------------------------------------*/
Transaction* TransactionFactory::createTransaction(MovieList* store, CustomerList* customers, string line) {
    Transaction* t = nullptr;
    Customer* customer = nullptr;
    Movie* movie = nullptr;
    string command, movieType, mediaType, rawId;
    istringstream iss(line);
    getline(iss, command, ' ');
    char c = command[0];
    switch(c) {
        case 'B' :
            getline(iss, rawId, ' ');
            getline(iss, mediaType, ' ');
            getline(iss, movieType, ' ');
            customer = customers->get(stoi(rawId));
            movie = MovieFactory::makePartialMovie(movieType[0], iss);
            t = new Borrow(store, customer, movie);
            break;
        case 'R' : 
            getline(iss, rawId, ' ');
            getline(iss, mediaType, ' ');
            getline(iss, movieType, ' ');
            customer = customers->get(stoi(rawId));
            movie = MovieFactory::makePartialMovie(movieType[0], iss);
            t = new Return(store, customer, movie);
            break;
        case 'I' :
            t = new ViewInventory(store);
            break;
        case 'H' :
            getline(iss, rawId, ' ');
            customer = customers->get(stoi(rawId));
            t = new ViewHistory(customer);
            break;
        default:
            break;
    }
    return t;
}