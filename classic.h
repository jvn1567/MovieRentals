#ifndef _CLASSIC_H
#define _CLASSIC_H

#include "movie.h"

class Classic : public Movie {
public:
    Classic(char type, string title, string director, string majorActor,
            int releaseMonth, int releaseYear);
    Classic* actorlessCopy() const;
    virtual string toString() const;
    virtual string toStringShort() const;
private:
    string majorActor;
    int releaseMonth;
    virtual bool lessThan(const Movie& other) const;
    virtual bool equalTo(const Movie& other) const;
};

#endif