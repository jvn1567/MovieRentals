#include "transaction.h"
#include "transactionfactory.h"
#include "moviefactory.h"
#include "borrow.h"
#include "return.h"
#include "viewhistory.h"
#include "viewInventory.h"
#include "businesslogic.h"

TransactionFactory::TransactionFactory() {

}

string removeEndingComma(string word) {
    if (word[word.length()] == ',') {
        return word.substr(0, word.length() - 1);
    } else {
        return word;
    }
}

Movie* TransactionFactory::getMovie(map<Movie*, int>* store, string movieType, istringstream& iss) {
    Movie* movie = nullptr;
    if (movieType == "C") {
        int month, year;
        string director;

        iss >> month;
        iss >> year;
        getline(iss, director);

        for (auto& kv: *store) {
            Movie* tempMovie = kv.first;
            int count = kv.second;
            if (tempMovie->getType() == movieType && tempMovie->getReleaseYear() == year && tempMovie->getDirector() == director) {
                movie = tempMovie;
            }
        }
    } else if (movieType == "D") {
        string director, title;
        getline(iss, director, ',');
        getline(iss, title, ',');
        for (auto& kv: *store) {
            Movie* tempMovie = kv.first;
            int count = kv.second;
            if (tempMovie->getType() == movieType && tempMovie->getDirector() == director && tempMovie->getTitle() == title) {
                movie = tempMovie;
            }
        }
    } else if (movieType == "F") {
        string title;
        int year;
        getline(iss, title, ',');
        iss >> year;
        for (auto& kv: *store) {
            Movie* tempMovie = kv.first;
            int count = kv.second;
            if (tempMovie->getType() == movieType && tempMovie->getTitle() == title && tempMovie->getReleaseYear() == year) {
                movie = tempMovie;
            }
        }
    }
    return movie;
}

Transaction* TransactionFactory::createTransaction(map<Movie*, int>* store, string line) {
    string command, movieType, mediaType;
    istringstream iss(line);
    iss >> command;

    Transaction* t = nullptr;

    char c = command[0];
    int customerId;
    switch(c) {
        case 'B' :
            iss >> customerId;
            iss >> mediaType;
            iss >> movieType;
            Movie* movie = getMovie(store, movieType, iss); //retrive Movie
            t = new Borrow(customerId, movie);
            break;
        case 'R' : 
            iss >> customerId;
            iss >> mediaType;
            iss >> movieType;
            Movie* movie = getMovie(store, movieType, iss); //retrive Movie
            t = new Return(movie);
            break;
        case 'I' :
            t = new ViewInventory();
            break;
        case 'H' :
            iss >> customerId;
            t = new ViewHistory(customerId);
            break;
        default:
            cout << "Invalid Command" << endl;
            break;
    }
    return t;
}