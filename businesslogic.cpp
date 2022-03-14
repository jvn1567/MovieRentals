#include "businesslogic.h"
#include "transaction.h"
#include "transactionfactory.h"
#include "movieFactory.h"
#include "customerlist.h"
#include "customer.h"
#include <sstream>
#include <fstream>

using namespace std;

BusinessLogic::BusinessLogic() {
    customers = new CustomerList;
    store = new MovieList;
}

BusinessLogic::~BusinessLogic() {
    delete store;
    delete customers;
}

bool BusinessLogic::buildMovies(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
        cout << "File could not be opened." << endl;
        return false;
    }
    string line = "";
    getline(infile, line);
    while(!infile.eof()) { //read through each line
        if (!line.empty()) {
            istringstream iss(line);
            string rawType, rawCount;
            char movieType;
            getline(iss, rawType, ' ');
            movieType = rawType[0];
            getline(iss, rawCount, ' ');
            rawCount = rawCount.substr(0, rawCount.length() - 1);
            int count = stoi(rawCount);
            Movie* movie = MovieFactory::makeMovie(movieType, iss);
            if (movie != nullptr) {
                store->insert(movie, count);
            }
        }
        getline(infile, line);
    }
    return true;
}

bool BusinessLogic::buildCustomers(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
	    cout << "File could not be opened." << endl;
		return false;
	}
    string line = "";
    getline(infile, line);
    while(!infile.eof()) { //read through each line
        if (!line.empty()) {
            istringstream iss(line);
            int customerId;
            string firstName, lastName;
            iss >> customerId >> lastName >> firstName;
            Customer* newCustomer = new Customer(customerId);
            customers->add(newCustomer);
        }
        getline(infile, line);
    }
    return true;
}


bool BusinessLogic::processTransactions(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
		cout << "File could not be opened." << endl;
		return false;
	}
    string line = "";
    getline(infile, line);
    while(!infile.eof()) {
        cout << line << endl; // DEBUG REMOVE BEFORE FINAL
        TransactionFactory tf;
        if (!line.empty()) { //read through each line
            Transaction* t = tf.createTransaction(store, customers, line);
            if (t != nullptr) {
                bool success = t->doTransaction();
                if (!success) {
                    cout << "Transaction failed." << endl << endl;
                }
                delete t;
            } else {
                cout << "Invalid Command" << endl << endl;
            }
        }
        getline(infile, line);
    }
    return true;
}
