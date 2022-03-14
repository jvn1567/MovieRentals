#include "transaction.h"
#include "transactionfactory.h"
#include "moviefactory.h"
#include "movielist.h"
#include "borrow.h"
#include "return.h"
#include "viewhistory.h"
#include "viewinventory.h"
#include "businesslogic.h"

/*
string removeEndingComma(string word) {
    if (word[word.length()] == ',') {
        return word.substr(0, word.length() - 1);
    } else {
        return word;
    }
}
*/

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
            if (customer != nullptr) {
                t = new Borrow(store, customer, movie);
            }
            break;
        case 'R' : 
            getline(iss, rawId, ' ');
            getline(iss, mediaType, ' ');
            getline(iss, movieType, ' ');
            customer = customers->get(stoi(rawId));
            movie = MovieFactory::makePartialMovie(movieType[0], iss);
            if (customer != nullptr) {
                t = new Return(store, customer, movie);
            }
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