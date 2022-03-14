#include "moviefactory.h"

Movie* MovieFactory::makeMovie(char type, istringstream& input) {
    string title, director, yearRaw, discard;
    string actor, actorFirst, actorLast, monthRaw;
    int year, month;
    Movie* movie = nullptr;
    // assuming no misformated lines, regarless of valid type
    getline(input, director, ',');
    getline(input, title, ',');
    title = title.substr(1);
    // create object based on format-specific type
    switch (type) {
        case 'F': // comedy
            getline(input, yearRaw);
            year = stoi(yearRaw.substr(1));
            movie = new Comedy(type, title, director, year);
            break;
        case 'D': // drama
            getline(input, yearRaw);
            year = stoi(yearRaw.substr(1));
            movie = new Drama(type, title, director, year);
            break;
        case 'C': // classic
            getline(input, discard, ' ');
            getline(input, actorFirst, ' ');
            getline(input, actorLast, ' ');
            getline(input, monthRaw, ' ');
            getline(input, yearRaw);
            year = stoi(yearRaw);
            month = stoi(monthRaw);
            actor = actorFirst + " " + actorLast;
            movie = new Classic(type, title, director, actor, month, year);
            break;
        default:
            break;
    }
    return movie;
}

// empty strings for attributes that don't get compared or sorted
Movie* MovieFactory::makePartialMovie(char type, istringstream& input) {
    Movie* movie = nullptr;
    string title, director, actor, monthRaw, yearRaw, firstActor, lastActor;
    int month, year;
    switch (type) {
        case 'F': // comedy
            getline(input, title, ',');
            getline(input, yearRaw);
            year = stoi(yearRaw);
            movie = new Comedy(type, title, "", year);
            break;
        case 'D': // drama
            getline(input, director, ',');
            getline(input, title, ',');
            title = title.substr(1);
            movie = new Drama(type, title, director, 0);
            break;
        case 'C': // classic
            getline(input, monthRaw, ' ');
            getline(input, yearRaw, ' ');
	    input >> firstActor >> lastActor;
            month = stoi(monthRaw);
            year = stoi(yearRaw);
            movie = new Classic(type, "", "", firstActor + " " + lastActor, month, year);
            break;
        default:
            break;
    }
    return movie;
}