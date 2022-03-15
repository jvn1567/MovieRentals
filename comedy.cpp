/**
 * @file comedy.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a comedy movie.
 * @date 2022-03-14
 */

#include "comedy.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Creates a Comedy movie with the specified attributes.
 ------------------------------------------------------------------*/
Comedy::Comedy(char type, string title, string director, int releaseYear) :
    Movie(type, title, director, releaseYear) {
}

/**------------------------------------------------------------------
 * Less Than
 * 
 * Returns true if this movie is considered less than the passed in
 * movie. Comedies are considered less if their title comes first
 * alphabetically. If titles match, the comedy with the earliest
 * year is less.
 ------------------------------------------------------------------*/
bool Comedy::lessThan(const Movie& other) const {
    bool titleLess = title < other.getTitle();
    bool titleSame = title == other.getTitle();
    bool yearLess = releaseYear < other.getReleaseYear();
    return titleLess || (titleSame && yearLess);
}

/**------------------------------------------------------------------
 * Equal To
 * 
 * Returns true if this movie has the same title and release year
 * as the one passed in.
 ------------------------------------------------------------------*/
bool Comedy::equalTo(const Movie& other) const {
    bool titleSame = title == other.getTitle();
    bool yearSame = releaseYear == other.getReleaseYear();
    return titleSame && yearSame;
}

/**------------------------------------------------------------------
 * To String Short
 * 
 * Returns a string displaying the sorting attributes of the movie,
 * in the same format as the commands input text file.
 ------------------------------------------------------------------*/
string Comedy::toStringShort() const {
    return title + ", " + to_string(releaseYear);
}