/**
 * @file movielist.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a list of movies, stored in a BST.
 * @date 2022-03-14
 */

#ifndef _MOVIELIST_H
#define _MOVIELIST_H    

#include "movie.h"
#include <sstream>

using namespace std;

class MovieList {
public:

    // Constructor / Destructor
    MovieList();
    ~MovieList();

    // Insert / Remove
    void insert(Movie* movie, int count = 1);
    bool remove(Movie* movie, int count = 1);

    // Accessors
    int count(Movie* movie) const;

    // Get full movie information from sorting information
    Movie* findMovie(Movie* movie) const;

    // Print inventory
    void viewInventory() const;

private:

    // Tree node for movie and count
    struct MovieNode {
        Movie* movie;
        int count;
        MovieNode* left;
        MovieNode* right;
        // Constructor
        MovieNode(Movie* movie, int count = 0, MovieNode* left = nullptr,
                MovieNode* right = nullptr);
    };

    //Helpers
    void deleteHelper(MovieNode*& node);
    void insertHelper(MovieNode*& node, Movie* movie, int count);
    bool removeHelper(MovieNode*& node, Movie* movie, int count);
    Movie* findMovieHelper(MovieNode* node, Movie* movie) const;
    void viewInventoryHelper(MovieNode* curr) const;

    // Members
    MovieNode* root;
    int items;

};

#endif