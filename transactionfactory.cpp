#include "transaction.h"
#include "transactionfactory.h"
#include "moviefactory.h"
#include "borrow.h"
#include "return.h"
#include "viewhistory.h"
#include "viewInventory.h"
#include "businesslogic.h"

TransactionFactory::TransactionFactory() {

}

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
    string command, movieType, mediaType;
    int customerId;
    istringstream iss(line);
    
    iss >> command; 
    char c = command[0];
    switch(c) {
        case 'B' :
            iss >> customerId;
            iss >> mediaType;
            iss >> movieType;
            customer = customers->get(customerId);
            movie = MovieFactory::makePartialMovie(c, iss);
            if (customer != nullptr) {
                t = new Borrow(store, customer, movie);
            }
            break;
        case 'R' : 
            iss >> customerId;
            iss >> mediaType;
            iss >> movieType;
            customer = customers->get(customerId);
            movie = MovieFactory::makePartialMovie(c, iss);
            if (customer != nullptr) {
                t = new Return(store, customer, movie);
            }
            break;
        case 'I' :
            t = new ViewInventory(store);
            break;
        case 'H' :
            iss >> customerId;
            customer = customers->get(customerId);
            t = new ViewHistory(customer);
            break;
        default:
            cout << "Invalid Command" << endl;
            break;
    }
    return t;
}