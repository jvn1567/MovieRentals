#include "comedy.h"

Comedy::Comedy(string type, string title, string director, int releaseYear) :
    Movie(type, title, director, releaseYear) {
}

bool Comedy::lessThan(const Movie& other) const {
    bool titleLess = title < other.getTitle();
    bool titleSame = title == other.getTitle();
    bool yearLess = releaseYear < other.getReleaseYear();
    return titleLess || (titleSame && yearLess);
}

bool Comedy::equalTo(const Movie& other) const {
    bool titleSame = title == other.getTitle();
    bool yearSame = releaseYear == other.getReleaseYear();
    return titleSame && yearSame;
}