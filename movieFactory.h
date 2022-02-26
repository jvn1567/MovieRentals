#ifndef _MOVIEFACTORY_H
#define _MOVIEFACTORY_H

#include <sstream>
#include "classic.h"
#include "comedy.h"
#include "drama.h"

class MovieFactory {
public:
    static Movie* makeMovie(string type, istringstream& input);
};

#endif