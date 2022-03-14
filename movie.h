#ifndef _MOVIE_H
#define _MOVIE_H

#include <string>
#include <iostream>
using namespace std;

class Movie {
public:
    Movie(char type, string title, string director, int releaseYear);
    virtual ~Movie();
    char getType() const;
    string getTitle() const;
    string getDirector() const;
    int getReleaseYear() const;
    bool operator<(const Movie& other) const;
    bool operator==(const Movie& other) const;
    virtual string toString() const;
    virtual string toStringShort() const = 0;
protected:
    char type;
    string title;
    string director;
    int releaseYear;
private:
    virtual bool lessThan(const Movie& other) const = 0;
    virtual bool equalTo(const Movie& other) const = 0;
};
#endif