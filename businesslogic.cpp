#include "businesslogic.h"
#include "transaction.h"
#include "transactionfactory.h"
#include "movieFactory.h"
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
    while(!infile.eof()) { //read through each line
        string line = "";
        getline(infile, line);
        if (!line.empty()) {
            istringstream iss(line);
            string rawType, rawCount;
            char movieType;
            getline(iss, rawType, ' ');
            movieType = rawType[0];
            getline(iss, rawCount, ' ');
            rawCount = rawCount.substr(0, rawCount.length() - 1);
            int count = stoi(rawCount);
            store->insert(MovieFactory::makeMovie(movieType, iss), count);
        }
    }
    return true;
}

bool BusinessLogic::buildCustomers(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
	    cout << "File could not be opened." << endl;
		return false;
	}
    while(!infile.eof()) { //read through each line
        string line = "";
        getline(infile, line);
        if (!line.empty()) {
            istringstream iss(line);
            int customerId;
            string firstName, lastName;
            iss >> customerId >> lastName >> firstName;
            customers->add(new Customer(customerId));
        }
    }
    return true;
}

bool BusinessLogic::processTransactions(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
		cout << "File could not be opened." << endl;
		return false;
	}
    TransactionFactory tf(store);
    while(!infile.eof()) {
        string line = "";
        getline(infile, line);
        if (!line.empty()) { //read through each line
            string command;
            istringstream iss(line);
            iss >> command;
            Transaction* t = tf.createTransaction(command, iss);
            if (t != nullptr) {
                t->doTransaction(customers);
            }  
        }
    }
    return true;
}