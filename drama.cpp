#include "drama.h"

Drama::Drama(char type, string title, string director, int releaseYear) :
    Movie(type, title, director, releaseYear) {
}

bool Drama::lessThan(const Movie& other) const {
    bool directorLess = director < other.getDirector();
    bool directorSame = director == other.getDirector();
    bool titleLess = title < other.getTitle();
    return directorLess || (directorSame && titleLess);
}

bool Drama::equalTo(const Movie& other) const {
    bool directorSame = director == other.getDirector();
    bool titleSame = title == other.getTitle();
    return directorSame && titleSame;
}