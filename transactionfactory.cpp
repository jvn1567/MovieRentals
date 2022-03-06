#include "transaction.h"
#include "transactionfactory.h"
#include "borrow.h"
#include "return.h"
#include "viewhistory.h"
#include "viewInventory.h"
#include "businesslogic.h"

using namespace std;

Transaction* TransactionFactory::createTransaction(string command, movieNode root, istringstream& iss) {
  Transaction* t = nullptr;
  char c = command[0];
  switch(c) {
    case 'B' :
      t = new Borrow(root);
      break;
    case 'R' : 
      t = new Return(root);
      break;
    case 'I' :
      t = new ViewInventory(root);
      break;
    case 'H' :
      t = new ViewHistory(root);
      break;
    default:
      cout << "Invalid Command" << endl;
  }
  return t;
}