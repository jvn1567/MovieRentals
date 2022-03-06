#include "businesslogic.h"
#include "transaction.h"
#include "transactionfactory.h"
#include <sstream>
#include <fstream>

using namespace std;

BusinessLogic::BusinessLogic() {}

bool BusinessLogic::buildMovies(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
        cout << "File could not be opened." << endl;
        return false;
    }
    Transaction::setInventory(store);
    return true;
}

bool BusinessLogic::buildCustomers(string filename) {
    ifstream infile(filename);
    if (!infile.good()) {
	    cout << "File could not be opened." << endl;
		return false;
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
        string line = "";
        getline(infile, line);
        if (!line.empty()) { //read through each line
            string command;
            istringstream iss(line);
            iss >> command;
            Transaction* t = TransactionFactory::createTransaction(command, iss);
            if (t != nullptr) {
                t->doTransaction(nullptr, "");
            }  
        }
    }
    return true;
}