#ifndef _DRAMA_H
#define _DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
    Drama(char type, string title, string director, int releaseYear);
private:
    virtual bool lessThan(const Movie& other) const;
    virtual bool equalTo(const Movie& other) const;
};

#endif