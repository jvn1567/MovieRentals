/**
 * @file drama.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a drama movie.
 * @date 2022-03-14
 */

#include "drama.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Creates a Drama with the specified attributes.
 ------------------------------------------------------------------*/
Drama::Drama(char type, string title, string director, int releaseYear) :
    Movie(type, title, director, releaseYear) {
}

/**------------------------------------------------------------------
 * Less Than
 * 
 * Returns true if this movie is considered less than the passed in
 * movie. Dramas are less if their director is first alphabetically.
 * If directors are the same, the Drama with the first title
 * alphabetically is less than the other.
 ------------------------------------------------------------------*/
bool Drama::lessThan(const Movie& other) const {
    bool directorLess = director < other.getDirector();
    bool directorSame = director == other.getDirector();
    bool titleLess = title < other.getTitle();
    return directorLess || (directorSame && titleLess);
}

/**------------------------------------------------------------------
 * Equal To
 * 
 * Returns true if both movies have the same title and director.
 ------------------------------------------------------------------*/
bool Drama::equalTo(const Movie& other) const {
    bool directorSame = director == other.getDirector();
    bool titleSame = title == other.getTitle();
    return directorSame && titleSame;
}

/**------------------------------------------------------------------
 * To String Short
 * 
 * Returns a string displaying the sorting attributes of the movie,
 * in the same format as the command input text file.
 ------------------------------------------------------------------*/
string Drama::toStringShort() const {
    return director + ", " + title + ",";
}