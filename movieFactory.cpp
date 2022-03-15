/**
 * @file moviefactory.cpp
 * @author Matthew Kim, John Nguyen CSS502 
 * @brief This class generates movies of the correct subclass.
 * @date 2022-03-14
 */

#include "moviefactory.h"

/**------------------------------------------------------------------
 * Make Movie
 * 
 * Creates a movie object of the correct subclass by taking the type
 * as a char and a reference to an input string stream containing
 * the rest of the movie information. Format of the string in the
 * stream is assumed to be valid.
 ------------------------------------------------------------------*/
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

/**------------------------------------------------------------------
 * Make Partial Movie
 * 
 * Creates movie objects of the subclass corresponding to the passed
 * in type, by reading from the input string stream reference
 * provided. Format being read in is assumed to be correct. Objects
 * created by this method only contain sorting attributes, with
 * empty strings or 0 as defaults for unprovided attributes.
 ------------------------------------------------------------------*/
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