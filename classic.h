/**
 * @file classic.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a classic movie.
 * @date 2022-03-14
 */

#ifndef _CLASSIC_H
#define _CLASSIC_H

#include "movie.h"

class Classic : public Movie {
public:

    // Constructor
    Classic(char type, string title, string director, string majorActor,
            int releaseMonth, int releaseYear);

    // Special case copy with empty string for actor
    Classic* actorlessCopy() const;

    // String dispaly methods
    virtual string toString() const;
    virtual string toStringShort() const;

private:

    // Private members
    string majorActor;
    int releaseMonth;

    // Polymorphic methods for operators == and <
    virtual bool lessThan(const Movie& other) const;
    virtual bool equalTo(const Movie& other) const;
    
};

#endif