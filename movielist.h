// TODO: real header
// A map of movies and their counts implemented as a BST

#ifndef _MOVIELIST_H
#define _MOVIELIST_H    

#include "movie.h"

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

    //Helpers
    void insertHelper(MovieNode*& node, Movie* movie, int count);
    bool removeHelper(MovieNode*& node, Movie* movie, int count);
    void deleteHelper(MovieNode*& node);

    // Members
    MovieNode* root;
    int items;

};

#endif