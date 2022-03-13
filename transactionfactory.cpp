#include "transactionfactory.h"
#include "moviefactory.h"
#include "borrow.h"
#include "return.h"
#include "viewhistory.h"
#include "viewInventory.h"
#include "businesslogic.h"

Transaction* TransactionFactory::createTransaction(string command, istringstream& iss) {
    Transaction* t = nullptr;
    char c = command[0];
    switch(c) {
        case 'B' :
            iss >> customerId;
            iss >> movieType;
            Movie* movie = MovieFactory::getMovie(movieType, iss); //retrive Movie
            t = new Borrow(store, customer, movie);
            break;
        case 'R' : 
            
            Movie* movie = MovieFactory::getMovie(movieType, iss); //retrive Movie
            t = new Return(store, customer, movie);
            break;
        case 'I' :
            t = new ViewInventory();
            break;
        case 'H' :
            t = new ViewHistory();
            break;
        default:
        cout << "Invalid Command" << endl;
    }
    return t;
}