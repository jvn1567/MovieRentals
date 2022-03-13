#include "classic.h"

Classic::Classic(char type, string title, string director,
        string majorActor, int releaseMonth, int releaseYear) :
    Movie(type, title, director, releaseYear),
    majorActor(majorActor),
    releaseMonth(releaseMonth) {
}

bool Classic::lessThan(const Movie& other) const {
    Classic* otherC = (Classic*)&other;
    int releaseThis = (releaseYear * 12 + releaseMonth); // works to year 2666
    int releaseOther = (otherC->releaseYear * 12 + otherC->releaseMonth);
    bool releaseLess = releaseThis < releaseOther;
    bool releaseEqual = releaseThis == releaseOther;
    bool actorLess = majorActor < otherC->majorActor;
    return releaseLess || (releaseEqual && actorLess);
}

bool Classic::equalTo(const Movie& other) const {
    Classic* otherC = (Classic*)&other;
    int releaseThis = (releaseYear * 12 + releaseMonth); // works to year 2666
    int releaseOther = (otherC->releaseYear * 12 + otherC->releaseMonth);
    bool releaseEqual = releaseThis == releaseOther;
    bool actorEqual = majorActor < otherC->majorActor;
    // special case for same movie with different actor listed
    bool ignoreActor = majorActor == "" || otherC->majorActor == "";
    return releaseEqual && (actorEqual || ignoreActor);
}