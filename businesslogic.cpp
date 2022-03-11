#include "businesslogic.h"
#include "transaction.h"
#include "transactionfactory.h"
#include "movieFactory.h"
#include <sstream>
#include <fstream>

using namespace std;

BusinessLogic::BusinessLogic() {
    arraySize = 101;
    customers = new CustomerNode*[arraySize];
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
            store[MovieFactory::makeMovie(movieType, iss)] += count;
        }
    }
    Transaction::setInventory(store);
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
    while(!infile.eof()) {
        string line = "";
        getline(infile, line);
        //add customers to hash
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
                t->doTransaction(store, customers);
            }  
        }
    }
    return true;
}