#ifndef _CLASSIC_H
#define _CLASSIC_H

#include "movie.h"

class Classic : public Movie {
public:
    Classic(string type, string title, string director, string majorActor,
            int releaseMonth, int releaseYear);
private:
    string majorActor;
    int releaseMonth;
    virtual bool lessThan(const Movie& other) const;
    virtual bool equalTo(const Movie& other) const;
};

#endif