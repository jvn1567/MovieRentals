/**
 * @file businesslogic.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief Defines the logic to build the movie rental store and process commands
 * @date 2022-03-14
 */

#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H

#include "customerlist.h"
#include "movie.h"
#include "movielist.h"

using namespace std;

// A class representing a general transaction.
class BusinessLogic {
public:
    /**------------------------------------------------------------------
     * Constructor
     * 
     * Constructor that creates a new CustomerList and MovieList.
     ------------------------------------------------------------------*/
    BusinessLogic();

    /**------------------------------------------------------------------
     * Destructor
     * 
     * Clears heap-allocated memory.
     ------------------------------------------------------------------*/
    ~BusinessLogic();

    /**------------------------------------------------------------------
     * buildMovies
     * 
     * Builds the store's inventory of movies from an input file.
     * Parameter: filename is the file name of the input file.
     * Return: True if the store's inventory was successfully built from
     * the input file.
     ------------------------------------------------------------------*/
    bool buildMovies(string filename);

    /**------------------------------------------------------------------
     * buildCustomers
     * 
     * Builds the store's customer list from an input file.
     * Parameter: filename is the file name of the input file.
     * Return: True if the store's customer list was successfully built
     * from the input file.
     ------------------------------------------------------------------*/
    bool buildCustomers(string filename);

    /**------------------------------------------------------------------
     * processTransactions
     * 
     * Performs movie rental transations based on commands from an input
     * file.
     * Parameter: filename is the file name of the input file.
     * Return: True if all the transactions were successfully processed.
     ------------------------------------------------------------------*/
    bool processTransactions(string filename);
    
private:
    MovieList* store;
    CustomerList* customers;
};

#endif