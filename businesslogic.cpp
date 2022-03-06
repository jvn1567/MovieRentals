#include "businesslogic.h"
#include "transaction.h"
#include "transactionfactory.h"
#include <sstream>
#include <fstream>

using namespace std;

bool BusinessLogic::buildMovies(string filename) {
  ifstream infile(filename);
	if (!infile.good()) {
		cout << "File could not be opened." << endl;
		return false;
	}

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
  TransactionFactory tf;
  while(!infile.eof()) {
    string line = "";
    getline(infile, line);
    if (!line.empty()) { //read through each line
      string command;
      istringstream iss(line);
      iss >> command;
      Transaction* t = tf.createTransaction(command, root, iss);
      if (t != nullptr) {
        t->doTransaction();
      }  
    }
  }
  return true;
}