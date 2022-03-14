/**
 * @file comedy.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a comedy movie.
 * @date 2022-03-14
 */

#ifndef _COMEDY_H
#define _COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:

    // Constructor
    Comedy(char type, string title, string director, int releaseYear);

    // Display method
    virtual string toStringShort() const;

private:

    // Polymporphic methods for operator == and <
    virtual bool lessThan(const Movie& other) const;
    virtual bool equalTo(const Movie& other) const;
    
};

#endif