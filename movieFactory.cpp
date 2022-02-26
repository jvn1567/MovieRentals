#include "movieFactory.h"

Movie* MovieFactory::makeMovie(string type, istringstream& input) {
    string title, director, yearRaw;
    Movie* movie;
    // assuming no misformated lines, regarless of valid type
    getline(input, director, ',');
    getline(input, title, ',');
    // create object based on format-specific type
    if (type == "F") { // comedy
        getline(input, yearRaw);
        int year = stoi(yearRaw);
        movie = new Comedy(type, title, director, year);
    } else if (type == "D") { // drama
        getline(input, yearRaw);
        int year = stoi(yearRaw);
        movie = new Drama(type, title, director, year);
    } else if (type == "C") { // classic
        string actor, actorFirst, actorLast, monthRaw;
        getline(input, actorFirst, ' ');
        getline(input, actorLast, ' ');
        getline(input, monthRaw, ' ');
        getline(input, yearRaw);
        int year = stoi(yearRaw);
        int month = stoi(monthRaw);
        actor = actorFirst + " " + actorLast;
        movie = new Classic(type, title, director, actor, month, year);
    } else { // invalid
        movie = nullptr;
    }
    return movie;
}