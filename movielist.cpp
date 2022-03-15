/**
 * @file movielist.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a list of movies, stored in a BST.
 * @date 2022-03-14
 */

#include "movielist.h"
#include <exception>
#include <sstream>

/**------------------------------------------------------------------
 * Constructor - Movie Node
 * 
 * Creates a new MovieNode object, with left and right default
 * values of nullptr if not provided.
 ------------------------------------------------------------------*/
MovieList::MovieNode::MovieNode(Movie* movie, int count,
        MovieNode* left, MovieNode* right) :
    movie(movie), count(count), left(left), right(right) {
}

/**------------------------------------------------------------------
 * Constructor - Movie List
 * 
 * Creates an empty MovieList.
 ------------------------------------------------------------------*/
MovieList::MovieList() {
    items = 0;
    root = nullptr;
}

/**------------------------------------------------------------------
 * Delete Helper
 * 
 * Clears heap-allocated memory from the passed in tree.
 ------------------------------------------------------------------*/
void MovieList::deleteHelper(MovieNode*& node) {
    if (node != nullptr) {
        deleteHelper(node->left);
        deleteHelper(node->right);
        delete node->movie;
        delete node;
    }
}

/**------------------------------------------------------------------
 * Destructor
 * 
 * Clears heap-allocated memory.
 ------------------------------------------------------------------*/
MovieList::~MovieList() {
    deleteHelper(root);
}

/**------------------------------------------------------------------
 * Insert Helper
 * 
 * Traverses the tree and places the passed in movie in a new node
 * with the specified count, or increases the existing movie's count
 * by the specified count.
 ------------------------------------------------------------------*/
void MovieList::insertHelper(MovieNode*& node, Movie* movie, int count) {
    if (node == nullptr) {
        node = new MovieNode(movie, count);
    } else if (*movie == *node->movie) {
        node->count += count;
    } else if (*movie < *node->movie) {
        insertHelper(node->left, movie, count);
    } else {
        insertHelper(node->right, movie, count);
    }
}

/**------------------------------------------------------------------
 * Insert
 * 
 * Adds the specified number of the passed in movie to the tree.
 * Throws exceptions for invalid movie or count.
 ------------------------------------------------------------------*/
void MovieList::insert(Movie* movie, int count) {
    if (movie == nullptr) {
        throw invalid_argument("Invalid movie - insert");
    } else if (count <= 0) {
        throw invalid_argument("Invalid count - insert");
    } else {
        insertHelper(root, movie, count);
    }
}

/**------------------------------------------------------------------
 * Remove Helper
 * 
 * Removes the specified amount of the passed in movie from the tree
 * and returns true, or returns false if there are not enough movies
 * or the movie is not found.
 ------------------------------------------------------------------*/
bool MovieList::removeHelper(MovieNode*& node, Movie* movie, int count) {
    if (node == nullptr || (*movie == *node->movie && node->count < count)) {
        return false;
    } else if (*movie == *node->movie) {
        node->count -= count;
        return true;
    } else if (*movie < *node->movie) {
        return removeHelper(node->left, movie, count);
    } else {
        return removeHelper(node->right, movie, count);
    }
}

/**------------------------------------------------------------------
 * Remove
 * 
 * Removes the specified amount of the passed in movie from the tree
 * and returns true, or returns false if there are not enough movies
 * or the movie is not found.
 * Throws exceptions for invalid movie or count.
 ------------------------------------------------------------------*/
bool MovieList::remove(Movie* movie, int count) {
    if (movie == nullptr) {
        throw invalid_argument("Invalid movie - remove");
    } else if (count <= 0) {
        throw invalid_argument("Invalid count - remove");
    } else {
        return removeHelper(root, movie, count);
    }
}

/**------------------------------------------------------------------
 * Count
 * 
 * Returns the count of the specified movie in the tree. If the
 * movie is not contained, returns -1.
 * An exception is thrown if movie is a nullptr.
 ------------------------------------------------------------------*/
int MovieList::count(Movie* movie) const {
    if (movie == nullptr) {
        throw invalid_argument("Invalid movie - count");
    }
    MovieNode* curr = root;
    while (curr != nullptr) {
        if (*movie == *curr->movie) {
            return curr->count;
        } else if (*movie < *curr->movie) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return -1;
}

/**------------------------------------------------------------------
 * Find Movie Helper
 * 
 * Returns the stored movie pointer if the movie matches the one
 * passed in. Otherwise returns nullptr. 
 ------------------------------------------------------------------*/
Movie* MovieList::findMovieHelper(MovieNode* node, Movie* movie) const {
    if (node == nullptr) {
        return nullptr;
    } else if (movie == node->movie) {
        return node->movie;
    } else if (movie < node->movie) {
        return findMovieHelper(node->left, movie);
    } else {
        return findMovieHelper(node->right, movie);
    }
}

/**------------------------------------------------------------------
 * Find Movie
 * 
 * Returns the stored movie pointer if the movie matches the one
 * passed in. Otherwise returns nullptr.
 ------------------------------------------------------------------*/
Movie* MovieList::findMovie(Movie* movie) const {
    return findMovieHelper(root, movie);
}

/**------------------------------------------------------------------
 * View Inventory Helper
 * 
 * Prints out the movies contained in the tree, and their counts,
 * in order.
 ------------------------------------------------------------------*/
void MovieList::viewInventoryHelper(MovieNode* curr) const {
    if (curr != nullptr) {
        viewInventoryHelper(curr->left);
        cout << curr->movie->getType() << ", " << curr->count;
        cout << ", " << curr->movie->toString() << endl;
        viewInventoryHelper(curr->right);
    }
}

/**------------------------------------------------------------------
 * View Inventory
 * 
 * Prints out the contents of the MovieList in order to the console.
 ------------------------------------------------------------------*/
void MovieList::viewInventory() const {
    cout << "Current store inventory:" << endl;
    viewInventoryHelper(root);
}