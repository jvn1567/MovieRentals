/**
 * @file moviefactory.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class generates movies of the correct subclass.
 * @date 2022-03-14
 */

#ifndef _MOVIEFACTORY_H
#define _MOVIEFACTORY_H

#include <sstream>
#include "classic.h"
#include "comedy.h"
#include "drama.h"

using namespace std;

class MovieFactory {
public:
    static Movie* makeMovie(char type, istringstream& input);
    static Movie* makePartialMovie(char type, istringstream& input);
};

#endif