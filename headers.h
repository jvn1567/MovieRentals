/**
 * @file headers.h
 * @author Mathew Kim, John Nguyen CSS502
 * @brief Class descriptions for Project 4.
 * @date 2022-02-17
 * 
 */

#include <string>
using namespace std;

// Contains information representing a movie.
struct Movie {
    int count;
    string type;
    string title;
    string director;
    int releaseYear;
    string majorActor;
    int releaseMonth;
    bool operator <(Movie& other) const;
};

// Reads in raw transaction data to create the correct Transaction type.
class TransactionFactory {
public:
    static Transaction* createTransaction(string command, istringstream* input);
};

// A class representing a general transaction.
class Transaction {
public:
    Transaction();
    virtual void doTransaction(Inventory* customer, string movie) const = 0;
    // sets the store inventory to add/remove from
    static void setInventory(Inventory* store);
private:
    static Inventory* store;
};

// A class representing a customer borrowing a movie from a store.
class Borrow : public Transaction {
public:
    Borrow();
    // Removes a movie from the store and adds it to the customer's inventory.
    virtual void doTransaction(CustomerInventory* customer, string movie) const;
};

// A class representing a customer putting a movie back in the store.
class Return : public Transaction {
public:
    Return();
    // Takes the movie from the customer's inventory and adds it back to the store.
    virtual void doTransaction(CustomerInventory* customer, string movie) const;
};

// A class representing a customer viewing their transaction history.
class ViewHistory : public Transaction {
public:
    ViewHistory();
    // Prints the customer's transaction history to console
    virtual void doTransaction(CustomerInventory* customer, string movie = "") const;
};

// A class representing a customer checking the store stock of movies.
class ViewInventory : public Transaction {
public:
    ViewInventory();
    // Prints the store's inventory to console.
    virtual void doTransaction(CustomerInventory* store = nullptr, string movie = "") const;
};

// Represents a general inventory of movies.
class Inventory {
public:
    Inventory(string filename);
    void add(string movieLine);
    void add(Movie* movie);
    void remove(Movie* movie);
    // prints all movies in the inventory to console
    void viewInventory() const;
private:
    struct MovieNode {
        Movie* movie;
        MovieNode* left;
        MovieNode* right;
        MovieNode(Movie* movie = nullptr, MovieNode* left = nullptr, MovieNode* right = nullptr);
    };
    MovieNode* movieList; // AVL
    int size; // movieList size
};

// Represents a specific customer's inventory and identification information.
class CustomerInventory : public Inventory {
public:
    CustomerInventory(int ID, string name);
    int getID() const;
    string getName() const;
    // prints transaction history to console
    void displayHistory() const;
private:
    int ID;
    string name;
    string* history;
    int size; // history size
};

// Reads input data files to create a store inventory and customer list, then
// processes transactions as specified in another text file.
class UI {
public:
    UI();
    // creates a store inventory from the specified text file
    void createInventory(string filename);
    // reads and processes customer data from text file
    void createCustomers(string filename);
    // reads and processes command data from text file
    void readCommands(string filename);
private:
    // generate hash index
     int hash (int ID) const;
    Inventory storeInventory;
    CustomerInventory** customerList; // stored in a hash table
    int size; // customerList size
};