#ifndef _MOVIE_H
#define _MOVIE_H

#include <string>
#include <iostream>
using namespace std;

class Movie {
public:
    Movie(string type, string title, string director, int releaseYear);
    string getType() const;
    string getTitle() const;
    string getDirector() const;
    int getReleaseYear() const;
    bool operator<(const Movie& other) const;
    bool operator==(const Movie& other) const;
protected:
    string type;
    string title;
    string director;
    int releaseYear;
private:
    virtual bool lessThan(const Movie& other) const = 0;
    virtual bool equalTo(const Movie& other) const = 0;
};

#endif