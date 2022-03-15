/**
 * @file movie.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a movie.
 * @date 2022-03-14
 */

#include "movie.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Creates a Movie with the specified attributes.
 ------------------------------------------------------------------*/
Movie::Movie(char type, string title, string director, int releaseYear) :
    type(type), title(title), director(director), releaseYear(releaseYear) {
}

/**------------------------------------------------------------------
 * Destructor
 * 
 * Clears heap-allocated memory.
 ------------------------------------------------------------------*/
Movie::~Movie() {}

/**------------------------------------------------------------------
 * Get Type
 * 
 * Returns a char representing the movie genre.
 ------------------------------------------------------------------*/
char Movie::getType() const {
    return type;
}

/**------------------------------------------------------------------
 * Get Title
 * 
 * Returns the movie title.
 ------------------------------------------------------------------*/
string Movie::getTitle() const {
    return title;
}

/**------------------------------------------------------------------
 * Get Director
 * 
 * Returns the director name.
 ------------------------------------------------------------------*/
string Movie::getDirector() const {
    return director;
}

/**------------------------------------------------------------------
 * Get Release Year
 * 
 * Returns the release year as an integer.
 ------------------------------------------------------------------*/
int Movie::getReleaseYear() const {
 return releaseYear;
}

/**------------------------------------------------------------------
 * Operator <
 * 
 * Overloads the less than operator for a movie. If the objects are
 * the same type, the polymorphic comparison functions are used
 * instead. Otherwise movies are sorted by type.
 * Returns true if this movie is less than the one passed in.
 ------------------------------------------------------------------*/
bool Movie::operator<(const Movie& other) const {
    if (type != other.type) {
        return type < other.type;
    } else {
        return this->lessThan(other);
    }
}

/**------------------------------------------------------------------
 * Operator ==
 * 
 * Returns true if the movies are the same type and have the same
 * sorting attributes.
 ------------------------------------------------------------------*/
bool Movie::operator==(const Movie& other) const {
    if (type != other.type) {
        return false;
    } else {
        return equalTo(other);
    }
}

/**------------------------------------------------------------------
 * To String
 * 
 * Returns a string displaying the full movie attributes, in the 
 * same format as the movie input text file.
 ------------------------------------------------------------------*/
string Movie::toString() const {
    return director + ", " + title + ", " + to_string(releaseYear);
}