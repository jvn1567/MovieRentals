#ifndef _COMEDY_H
#define _COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
    Comedy(char type, string title, string director, int releaseYear);
    virtual string toStringShort() const;
private:
    virtual bool lessThan(const Movie& other) const;
    virtual bool equalTo(const Movie& other) const;
};

#endif