// TODO: real header
// A map of movies and their counts implemented as a BST

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
    Movie* findMovie(char type, istringstream& input);

    void viewInventory();

private:

    // Tree node for movie and count
    struct MovieNode {
        Movie* movie;
        int count;
        MovieNode* left;
        MovieNode* right;
        // Constructor
        MovieNode(Movie* movie, int count, MovieNode* left = nullptr,
                MovieNode* right = nullptr);
    };

    Movie* findComedy(string title, int year);
    Movie* findDrama(string director, string title);
    Movie* findClassic(int month, int year, string actor);

    //Helpers
    void insertHelper(MovieNode*& node, Movie* movie, int count);
    bool removeHelper(MovieNode*& node, Movie* movie, int count);
    void deleteHelper(MovieNode*& node);
    void viewInventoryHelper(MovieNode* curr);

    // Members
    MovieNode* root;
    int items;

};

#endif