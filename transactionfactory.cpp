#include "transaction.h"
#include "transactionfactory.h"
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
            t = new Borrow();
            break;
        case 'R' : 
            t = new Return();
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