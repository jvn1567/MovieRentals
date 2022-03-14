/**
 * @file drama.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a drama movie.
 * @date 2022-03-14
 */

#ifndef _DRAMA_H
#define _DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:

    // Constructor
    Drama(char type, string title, string director, int releaseYear);

    // Display
    virtual string toStringShort() const;

private:

    // Polymorphic methods for operator == and <
    virtual bool lessThan(const Movie& other) const;
    virtual bool equalTo(const Movie& other) const;
    
};

#endif