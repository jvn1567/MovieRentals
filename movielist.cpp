#include "movielist.h"
#include <exception>
#include <sstream>

MovieList::MovieNode::MovieNode(Movie* movie, int count,
        MovieNode* left, MovieNode* right) :
    movie(movie), count(count), left(left), right(right) {
}

MovieList::MovieList() {
    items = 0;
    root = nullptr;
}

void MovieList::deleteHelper(MovieNode*& node) {
    if (node != nullptr) {
        deleteHelper(node->left);
        deleteHelper(node->right);
        delete node->movie;
        delete node;
    }
}

MovieList::~MovieList() {
    deleteHelper(root);
}

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

void MovieList::insert(Movie* movie, int count) {
    if (movie == nullptr) {
        throw invalid_argument("Invalid movie - insert");
    } else if (count <= 0) {
        throw invalid_argument("Invalid count - insert");
    } else {
        insertHelper(root, movie, count);
    }
}

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

bool MovieList::remove(Movie* movie, int count) {
    if (movie == nullptr) {
        throw invalid_argument("Invalid movie - remove");
    } else if (count <= 0) {
        throw invalid_argument("Invalid count - remove");
    } else {
        return removeHelper(root, movie, count);
    }
}

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
    return 0;
}

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

Movie* MovieList::findMovie(Movie* movie) const {
    return findMovieHelper(root, movie);
}

void MovieList::viewInventoryHelper(MovieNode* curr) const {
    if (curr != nullptr) {
        viewInventoryHelper(curr->left);
        cout << curr->movie->getType() << ", " << curr->count;
        cout << ", " << curr->movie->toString() << endl;
        viewInventoryHelper(curr->right);
    }
}

void MovieList::viewInventory() const {
    cout << "Current store inventory:" << endl;
    viewInventoryHelper(root);
}