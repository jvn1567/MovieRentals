/**
 * @file borrow.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a classic movie.
 * @date 2022-03-14
 */

#include "classic.h"

/**------------------------------------------------------------------
 * Constructor
 * 
 * Creates a classic movie with the passed in attributes
 ------------------------------------------------------------------*/
Classic::Classic(char type, string title, string director,
        string majorActor, int releaseMonth, int releaseYear) :
    Movie(type, title, director, releaseYear),
    majorActor(majorActor),
    releaseMonth(releaseMonth) {
}

/**------------------------------------------------------------------
 * Less Than
 * 
 * Returns true if this movie is considered less than the passed in
 * movie. Classics are less than another classic if their release
 * date is earlier. If release dates are the same, the movie with the
 * actor coming first alphabetically is less.
 ------------------------------------------------------------------*/
bool Classic::lessThan(const Movie& other) const {
    Classic* otherC = (Classic*)&other;
    int releaseThis = (releaseYear * 12 + releaseMonth); // works to year 2666
    int releaseOther = (otherC->releaseYear * 12 + otherC->releaseMonth);
    bool releaseLess = releaseThis < releaseOther;
    bool releaseEqual = releaseThis == releaseOther;
    bool actorLess = majorActor < otherC->majorActor;
    return releaseLess || (releaseEqual && actorLess);
}

/**------------------------------------------------------------------
 * Equal To
 * 
 * Returns true if this movie is equal to the passed in movie.
 * Clasics are considered equal if the release date and major actor
 * are the same.
 * This method also handles the special case where the title is used
 * instead if the major actor is an empty string.
 ------------------------------------------------------------------*/
bool Classic::equalTo(const Movie& other) const {
    Classic* otherC = (Classic*)&other;
    int releaseThis = (releaseYear * 12 + releaseMonth); // works to year 2666
    int releaseOther = (otherC->releaseYear * 12 + otherC->releaseMonth);
    bool releaseEqual = releaseThis == releaseOther;
    bool actorEqual = majorActor == otherC->majorActor;
    // special case for same movie with different actor listed
    bool ignoreActor = majorActor == "" || otherC->majorActor == "";
    bool titleEqual = title == otherC->title;
    return (releaseEqual && actorEqual) || (ignoreActor && titleEqual);
}

/**------------------------------------------------------------------
 * Actorless Copy
 * 
 * Creates a new Classic object with the same parameters as this one,
 * but with an empty string for the major actor.
 ------------------------------------------------------------------*/
Classic* Classic::actorlessCopy() const {
    return new Classic(type, title, director, "", releaseMonth, releaseYear);
}

/**------------------------------------------------------------------
 * To String
 * 
 * Returns a string displaying all attributes of this movie, in the
 * same format as the movies input text file.
 ------------------------------------------------------------------*/
string Classic::toString() const {
    string out = director + ", " + title + ", " + majorActor;
    return out + " " + to_string(releaseYear) + " " + to_string(releaseMonth);
}

/**------------------------------------------------------------------
 * To String Short
 * 
 * Returns a string displaying the sorting attributes of this movie,
 * in the same format as the commands input text file.
 ------------------------------------------------------------------*/
string Classic::toStringShort() const {
    return to_string(releaseMonth) + " " + to_string(releaseYear) + " " + majorActor;
}