#include "businesslogic.h"
#include "transaction.h"
#include "transactionfactory.h"
#include "movieFactory.h"
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

BusinessLogic::BusinessLogic() {
    arraySize = 101;
    customers = new CustomerNode*[arraySize];
    store = new map<Movie*, int>;
}

BusinessLogic::~BusinessLogic() {
    
}

bool BusinessLogic::buildMovies(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
        cout << "File could not be opened." << endl;
        return false;
    }
    while(!infile.eof()) {
        string line = "";
        getline(infile, line);
        if (!line.empty()) { //read through each line
            istringstream iss(line);
            string movieType, rawCount;
            getline(iss, movieType);
            movieType = movieType.substr(0, 1);
            getline(iss, rawCount);
            rawCount = rawCount.substr(0, rawCount.length() - 1);
            int count = stoi(rawCount);
            (*store)[MovieFactory::makeMovie(movieType, iss)] = count;
        }
    }
    return true;
}

void BusinessLogic::addCustomer(int customerId) {
    int index = hash(customerId);
    customers[index] = new CustomerNode(new Customer(customerId), customers[index]);
}

bool BusinessLogic::buildCustomers(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
	    cout << "File could not be opened." << endl;
		return false;
	}
    //add customers to hash
    while(!infile.eof()) {
        string line = "";
        getline(infile, line);
        if (!line.empty()) { //read through each line
            istringstream iss(line);
            int customerId;
            string firstName, lastName;
            iss >> customerId >> lastName >> firstName;
            addCustomer(customerId);
            getline(infile, line);
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
    
    while(!infile.eof()) {
        TransactionFactory tf;
        string line = "";
        getline(infile, line);
        
        if (!line.empty()) { //read through each line
            Transaction* t = tf.createTransaction(store, line);
            if (t != nullptr) {
                t->doTransaction(store, customers);
                delete t;
            }
        }
    }
    return true;
}