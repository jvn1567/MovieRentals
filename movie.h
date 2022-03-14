/**
 * @file movie.h
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class represents a movie.
 * @date 2022-03-14
 */

#ifndef _MOVIE_H
#define _MOVIE_H

#include <string>
#include <iostream>
using namespace std;

class Movie {
public:

    // Constructor and Destructor
    Movie(char type, string title, string director, int releaseYear);
    virtual ~Movie();

    // Accessors
    char getType() const;
    string getTitle() const;
    string getDirector() const;
    int getReleaseYear() const;

    // Operators 
    bool operator<(const Movie& other) const;
    bool operator==(const Movie& other) const;

    // Display methods
    virtual string toString() const;
    virtual string toStringShort() const = 0;

protected:

    // Members
    char type;
    string title;
    string director;
    int releaseYear;

private:

    // Polymorphic functions for operator < and ==
    virtual bool lessThan(const Movie& other) const = 0;
    virtual bool equalTo(const Movie& other) const = 0;
    
};
#endif