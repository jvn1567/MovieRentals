#include "movieFactory.h"

Movie* MovieFactory::makeMovie(char type, istringstream& input) {
    string title, director, yearRaw;
    int year, month;
    Movie* movie = nullptr;
    // assuming no misformated lines, regarless of valid type
    getline(input, director, ',');
    getline(input, title, ',');
    // create object based on format-specific type
    switch (type) {
        case 'F': // comedy
            getline(input, yearRaw);
            year = stoi(yearRaw);
            movie = new Comedy(type, title, director, year);
            break;
        case 'D': // drama
            getline(input, yearRaw);
            year = stoi(yearRaw);
            movie = new Drama(type, title, director, year);
            break;
        case 'C': // classic
            string actor, actorFirst, actorLast, monthRaw;
            getline(input, actorFirst, ' ');
            getline(input, actorLast, ' ');
            getline(input, monthRaw, ' ');
            getline(input, yearRaw);
            year = stoi(yearRaw);
            month = stoi(monthRaw);
            actor = actorFirst + " " + actorLast;
            movie = new Classic(type, title, director, actor, month, year);
            break;
    }
    return movie;
}

// empty strings for attributes that don't get compared or sorted
Movie* MovieFactory::makePartialMovie(char type, istringstream& input) {
    Movie* movie = nullptr;
    string title, director, actor, monthRaw, yearRaw;
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
            getline(input, actor);
            month = stoi(monthRaw);
            year = stoi(yearRaw);
            movie = new Classic(type, "", "", actor, month, year);
            break;
    }
    return movie;
}