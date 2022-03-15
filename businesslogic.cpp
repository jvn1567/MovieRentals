/**
 * @file businesslogic.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Defines the logic to build the movie rental store and process commands
 * @date 2022-03-14
 */

#include "businesslogic.h"
#include "transaction.h"
#include "transactionfactory.h"
#include "moviefactory.h"
#include "customerlist.h"
#include "customer.h"
#include <sstream>
#include <fstream>

using namespace std;

/**------------------------------------------------------------------
 * Constructor
 * 
 * Constructor that creates a new CustomerList and MovieList.
 ------------------------------------------------------------------*/
BusinessLogic::BusinessLogic() {
    customers = new CustomerList;
    store = new MovieList;
}

/**------------------------------------------------------------------
 * Destructor
 * 
 * Clears heap-allocated memory.
 ------------------------------------------------------------------*/
BusinessLogic::~BusinessLogic() {
    delete store;
    delete customers;
}

/**------------------------------------------------------------------
 * buildMovies
 * 
 * Builds the store's inventory of movies from an input file.
 * Parameter: filename is the file name of the input file.
 * Return: True if the store's inventory was successfully built from
 * the input file.
 ------------------------------------------------------------------*/
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

/**------------------------------------------------------------------
 * buildCustomers
 * 
 * Builds the store's customer list from an input file.
 * Parameter: filename is the file name of the input file.
 * Return: True if the store's customer list was successfully built
 * from the input file.
 ------------------------------------------------------------------*/
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

/**------------------------------------------------------------------
 * processTransactions
 * 
 * Performs movie rental transations based on commands from an input
 * file.
 * Parameter: filename is the file name of the input file.
 * Return: True if all the transactions were successfully processed.
 ------------------------------------------------------------------*/
bool BusinessLogic::processTransactions(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
		cout << "File could not be opened." << endl;
		return false;
	}
    string line = "";
    getline(infile, line);
    while(!infile.eof()) {
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
                cout << "Invalid Command: " << line[0] << endl << endl;
            }
        }
        getline(infile, line);
    }
    return true;
}
