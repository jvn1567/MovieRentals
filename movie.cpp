#include "movie.h"

Movie::Movie(string type, string title, string director, int releaseYear) :
    type(type), title(title), director(director), releaseYear(releaseYear) {
}

string Movie::getType() const {
    return type;
}

string Movie::getTitle() const {
    return title;
}

string Movie::getDirector() const {
    return director;
}

int Movie::getReleaseYear() const {
 return releaseYear;
}

bool Movie::operator<(const Movie& other) const {
    if (type != other.type) {
        return type < other.type;
    } else {
        return this->lessThan(other);
    }
}

bool Movie::operator==(const Movie& other) const {
    if (type != other.type) {
        return false;
    } else {
        return this->equalTo(other);
    }
}